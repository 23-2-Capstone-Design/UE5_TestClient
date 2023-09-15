// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Network/ClientSession.h"
#include "Network/PacketHeader.h"
#include "UE5_TestClientGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UE5_TESTCLIENT_API UUE5_TestClientGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

public:
	UClientSession* GetSession() { return Session; }
	TQueue<FPacketHeader*>& GetPacketQueueRef() { return PacketQueue; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Network")
	UClientSession* Session;

	TQueue<FPacketHeader*> PacketQueue;
};
