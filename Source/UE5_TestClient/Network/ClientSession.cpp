// Fill out your copyright notice in the Description page of Project Settings.


#include "ClientSession.h"

UClientSession::UClientSession()
	: Socket(INVALID_SOCKET), Thread(nullptr), bIsConnected(false), bIsThreadRunning(false), bIsRegisteredSend(false)
{
	FD_ZERO(&ReadSet);
	FD_ZERO(&WriteSet);

	ServerAddress.sin_family = AF_INET;
	ServerAddress.sin_port = htons(PORT);
	inet_pton(AF_INET, TCHAR_TO_ANSI(*IP_ADDRESS), &ServerAddress.sin_addr);
}

UClientSession::~UClientSession()
{
	UE_LOG(LogTemp, Log, TEXT("~UClientSession()"));
	FD_ZERO(&ReadSet);
	FD_ZERO(&WriteSet);

	StopThread();
	Disconnect();
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
	while(bIsThreadRunning.Load())
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
	if (WSAStartup(MAKEWORD(2, 2), OUT & wsaData) != NO_ERROR)
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
			HandleError("connect Error");
			bIsConnected = false;
			return false;
		}
	}

	return true;
}

void UClientSession::Disconnect()
{
	// If this function is called and you want to reconnect, you must call InitSocket
	if (bIsConnected)
	{
		closesocket(Socket);
		Socket = INVALID_SOCKET;
		bIsConnected = false;
	}
}


void UClientSession::Send(SendBuffer Buffer)
{
	if(bIsConnected)
	{
		FScopeLock ScopeLock(&Lock);
		SendBuffers.Enqueue(Buffer);

		bIsRegisteredSend.Store(true);
		//TODO
	}
}

void UClientSession::HandleError(FString Cause)
{
	UE_LOG(LogTemp, Error, TEXT("Error[%d] %s "), WSAGetLastError(), *Cause);
	Disconnect();
}

bool UClientSession::RunThread()
{
	UE_LOG(LogTemp, Log, TEXT("RunThread"));
	if(Thread != nullptr)
	{
		return false;
	}

	Thread = FRunnableThread::Create(this, TEXT("NetworkThread"));
	return Thread != nullptr;
}

void UClientSession::StopThread()
{
	if(bIsThreadRunning.Load() == true)
	{
		Thread->Kill(false);
		delete Thread;
		Thread = nullptr;
	}

	if(bIsConnected)
	{
		Disconnect();
	}
}

int32 UClientSession::OnRecv(char* Buffer, int32 DataSize)
{
	// TODO HANDLE PACKET
	UE_LOG(LogTemp, Log, TEXT("OnRecv DataLen = %d"), DataSize);
	return DataSize;
}


void UClientSession::Dispatch()
{
	if(bIsConnected == false)
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
		HandleError("select Error");
		return;
	}
	else if (RetVal == 0)
	{
		HandleError("select Timeout");
		return;
	}

	// Recv
	if (FD_ISSET(Socket, &ReadSet))
	{
		int32 RecvLen = recv(Socket, RecvBuffer.GetBufferHead(), RecvBuffer.GetFreeSize(), 0);
		if (RecvLen == SOCKET_ERROR && WSAGetLastError() != WSAEWOULDBLOCK)
		{
			HandleError("recv Error");
			return;
		}

		if (RecvBuffer.WriteData(RecvLen) == false)
		{
			HandleError("WriteData Error");
			return;
		}

		const int32 DataSize = RecvBuffer.GetDataSize();
		int32 ProcessLen = OnRecv(RecvBuffer.GetBufferHead(), DataSize);
		if (ProcessLen < 0 || DataSize < ProcessLen || RecvBuffer.ReadData(ProcessLen) == false)
		{
			HandleError("ReadData Error");
			return;
		}

		RecvBuffer.CleanupBuffer();
	}

	// Send
	if (FD_ISSET(Socket, &WriteSet))
	{ 
		if (bIsRegisteredSend.Load())
		{
			FScopeLock ScopeLock(&Lock);
			// TODO
		}
	}
}