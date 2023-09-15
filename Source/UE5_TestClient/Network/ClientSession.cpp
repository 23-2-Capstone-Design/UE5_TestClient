// Fill out your copyright notice in the Description page of Project Settings.


#include "ClientSession.h"
#include "ServerPacketHandler.h"
#include "PacketHeader.h"

UClientSession::UClientSession()
	: Socket(INVALID_SOCKET), Thread(nullptr), bIsConnected(false), bIsThreadRunning(false), SendBufferDataSize(0)
{
	FD_ZERO(&ReadSet);
	FD_ZERO(&WriteSet);

	ServerAddress.sin_family = AF_INET;
	ServerAddress.sin_port = htons(PORT);
	inet_pton(AF_INET, TCHAR_TO_ANSI(*IP_ADDRESS), &ServerAddress.sin_addr);

	PlayerController = nullptr;
	GameInstance = nullptr;
}

UClientSession::~UClientSession()
{
	UE_LOG(LogTemp, Log, TEXT("~UClientSession()"));
	FD_ZERO(&ReadSet);
	FD_ZERO(&WriteSet);

	StopThread();
	Disconnect("~UClientSession()");
	WSACleanup();
}

bool UClientSession::Init()
{
	bIsThreadRunning.Store(true);
	return true;
}

uint32 UClientSession::Run()
{
	FPlatformProcess::Sleep(0.5f);
	while (bIsThreadRunning.Load())
	{
		Dispatch();
	}

	return 0;
}

void UClientSession::Stop()
{
	bIsThreadRunning.Store(false);
}

void UClientSession::Exit()
{
}

bool UClientSession::InitSocket()
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), OUT &wsaData) != NO_ERROR)
	{
		UE_LOG(LogTemp, Error, TEXT("Fail to WSAStartup "));
	}

	Socket = socket(AF_INET, SOCK_STREAM, 0);
	if (Socket == INVALID_SOCKET)
	{
		UE_LOG(LogTemp, Error, TEXT("Fail to socket"));
		return false;
	}

	int SocketReuse = 1;
	if (setsockopt(Socket, SOL_SOCKET, SO_REUSEADDR, (const char*)&SocketReuse, sizeof(int)) == SOCKET_ERROR)
	{
		UE_LOG(LogTemp, Error, TEXT("Fail to setsockopt"));
		return false;
	}

	u_long NonBlockingMode = 1;
	if (ioctlsocket(Socket, FIONBIO, &NonBlockingMode) != NO_ERROR)
	{
		UE_LOG(LogTemp, Error, TEXT("Fail to ioctlsocket"));
		return false;
	}

	return true;
}

bool UClientSession::Connect()
{
	while (true)
	{
		if (connect(Socket, (SOCKADDR*)&ServerAddress, sizeof(ServerAddress)) == SOCKET_ERROR)
		{
			int32 ErrorCode = WSAGetLastError();
			if (ErrorCode == WSAEWOULDBLOCK)
			{
				continue;
			}

			if (ErrorCode == WSAEISCONN)
			{
				bIsConnected = true;
				break;
			}

			// Error
			HandleError(ErrorCode);
			bIsConnected = false;
			return false;
		}
	}

	return true;
}

void UClientSession::Disconnect(FString Cause)
{
	// If this function is called and you want to reconnect, you must call InitSocket
	if (bIsConnected)
	{
		UE_LOG(LogTemp, Error, TEXT("Disconnect cause: %s"), *Cause);
		closesocket(Socket);
		Socket = INVALID_SOCKET;
		bIsConnected = false;
	}
}


void UClientSession::Send(USendBuffer* Buffer)
{
	if (IsConnected() == false)
	{
		UE_LOG(LogTemp, Log, TEXT("Send Error: not connected"));
		return;
	}

	SendQueue.Enqueue(Buffer);
}

void UClientSession::HandleError(int32 ErrorCode)
{
	switch (ErrorCode)
	{
	case WSAECONNRESET:
	case WSAECONNABORTED:
		Disconnect(L"HandleError");
		break;
	default:
		// TODO: Log
		Disconnect(L"HandleError");
		break;
	}
}

bool UClientSession::RunThread()
{
	UE_LOG(LogTemp, Log, TEXT("RunThread"));
	if (Thread != nullptr)
	{
		return false;
	}

	Thread = FRunnableThread::Create(this, TEXT("NetworkThread"));
	return Thread != nullptr;
}

void UClientSession::StopThread()
{
	if (bIsThreadRunning.Load() == true)
	{
		Thread->Kill(false);
		delete Thread;
		Thread = nullptr;
	}

	if (bIsConnected)
	{
		Disconnect("Stop Thread");
	}
}

bool UClientSession::ProcessRecv(int32 NumOfBytes)
{
	if (NumOfBytes == 0)
	{
		return false;
	}

	if (RecvBuffer.WriteData(NumOfBytes) == false)
	{
		return false;
	}

	int32 DataSize = RecvBuffer.GetDataSize();
	int32 ProcessSize = OnRecv(RecvBuffer.GetReadBufferPos(), DataSize);
	if (ProcessSize < 0 || DataSize < ProcessSize || RecvBuffer.ReadData(ProcessSize) == false)
	{
		Disconnect("");
		return false;
	}

	RecvBuffer.CleanupBuffer();
	return true;
}

int32 UClientSession::OnRecv(char* Buffer, int32 Len)
{
	int32 ProcessSize = 0;

	while (true)
	{
		int32 DataSize = Len - ProcessSize;

		// able parse PacketHeader
		if (DataSize < sizeof(FPacketHeader))
		{
			break;
		}

		FPacketHeader Header = *(reinterpret_cast<FPacketHeader*>(&Buffer[ProcessSize]));

		// able parse data
		if (DataSize < Header.Size)
		{
			break;
		}

		// TEMP LOG
		UE_LOG(LogTemp, Log, TEXT("OnRecv type: %d size: %d BufferFreeSize: %d"), Header.Type, Header.Size,
		       RecvBuffer.GetFreeSize());
		ServerPacketHandler::HandlePacket(this, &Buffer[ProcessSize], Header.Size);

		ProcessSize += Header.Size;

		break;
	}

	return ProcessSize;
}


void UClientSession::Dispatch()
{
	if (bIsConnected == false)
	{
		return;
	}

	FD_ZERO(&ReadSet);
	FD_ZERO(&WriteSet);

	FD_SET(Socket, &ReadSet);
	FD_SET(Socket, &WriteSet);

	timeval Timeout;
	Timeout.tv_sec = 3;
	Timeout.tv_usec = 0;

	int32 RetVal = select(0, &ReadSet, &WriteSet, nullptr, &Timeout);
	if (RetVal == SOCKET_ERROR)
	{
		int32 ErrorCode = WSAGetLastError();
		HandleError(ErrorCode);
		return;
	}
	if (RetVal == 0)
	{
		int32 ErrorCode = WSAGetLastError();
		HandleError(ErrorCode);
		return;
	}

	// Recv
	if (FD_ISSET(Socket, &ReadSet))
	{
		int32 RecvLen = recv(Socket, RecvBuffer.GetWriteBufferPos(), RecvBuffer.GetFreeSize(), 0);
		if (ProcessRecv(RecvLen) == false)
		{
			int32 ErrorCode = WSAGetLastError();
			HandleError(ErrorCode);
			return;
		}
	}

	// Send
	if (FD_ISSET(Socket, &WriteSet))
	{
		if (SendQueue.IsEmpty() == false)
		{
			USendBuffer* SendBuffer = nullptr;
			SendBuffers.Reset();
			while (SendQueue.Dequeue(SendBuffer))
			{
				int32 SendLen = send(Socket, SendBuffer->GetBuffer(), SendBuffer->GetSize(), 0);
				if (SendLen == SOCKET_ERROR)
				{
					int32 ErrorCode = WSAGetLastError();
					if (ErrorCode == WSAEWOULDBLOCK)
					{
						continue;
					}
					Disconnect("Send Error");
					break;
				}
			}
		}
	}
}
