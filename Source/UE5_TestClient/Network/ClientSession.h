// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RecvBuffer.h"
#include "SendBuffer.h"
#include <WinSock2.h>
#include <MSWSock.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#include "ClientSession.generated.h"

#define IP_ADDRESS FString("127.0.0.1")
#define PORT 3000

/**
 * 
 */
UCLASS()
class UE5_TESTCLIENT_API UClientSession : public UObject, public FRunnable, public TSharedFromThis<UClientSession>
{
	GENERATED_BODY()

public:
	UClientSession();
	virtual ~UClientSession() override;

public:
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;
	virtual void Exit() override;

public:
	bool IsConnected() { return bIsConnected; }
	bool IsThreadRunning() { return bIsThreadRunning.Load(); }

	// Network
public:
	bool InitSocket();
	bool Connect();
	void Disconnect(FString Cause);
	void Send(USendBuffer* Buffer);
	void HandleError(int32 ErrorCode);

	// Thread
public:
	bool RunThread();
	void StopThread();

	// Process Packet
protected:
	bool ProcessRecv(int32 NumOfBytes);
	int32 OnRecv(char* Buffer, int32 Len);
	void Dispatch();

protected:
	SOCKET Socket;
	FRunnableThread* Thread;
	bool bIsConnected;
	TAtomic<bool> bIsThreadRunning;
	SOCKADDR_IN ServerAddress;

	fd_set ReadSet;
	fd_set WriteSet;

	TQueue<USendBuffer*> SendQueue;
	TArray<USendBuffer*> SendBuffers;
	int32 SendBufferDataSize;
	RecvBuffer RecvBuffer;
};
