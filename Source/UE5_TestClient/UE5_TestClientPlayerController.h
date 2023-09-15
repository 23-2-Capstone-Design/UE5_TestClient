// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Network/ClientSession.h"
#include "Kismet/GameplayStatics.h"
#include "Network/Protocol/Packet.pb.h"
#include "UE5_TestClientGameInstance.h"
#include "UE5_TestClientPlayerController.generated.h"

using PacketHandlerFunc = TFunction<bool(UClientSession*, char*, int32)>;
extern PacketHandlerFunc GPacketHandler[UINT16_MAX];

bool Handle_Invalid(class UClientSession* Session, char* Buffer, int32 NumOfBytes);
bool Handle_S_JOIN(class UClientSession* Session, protocol::S_JOIN& Packet);
bool Handle_S_LEAVE(class UClientSession* Session, protocol::S_LEAVE& Packet);
bool Handle_S_MOVE(class UClientSession* Session, protocol::S_MOVE& Packet);

/**
 * 
 */
UCLASS()
class UE5_TESTCLIENT_API AUE5_TestClientPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AUE5_TestClientPlayerController();
	virtual ~AUE5_TestClientPlayerController() override;

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

protected:
	template <typename PacketType, typename ProcessFunc>
	static bool HandlePacket(ProcessFunc Func, UClientSession* Session, char* Buffer, int32 NumOfBytes)
	{
		PacketType Packet;
		if (Packet.ParseFromArray(Buffer + sizeof(FPacketHeader), NumOfBytes - sizeof(FPacketHeader)) == false)
		{
			return false;
		}
		return Func(Session, Packet);
	}

protected:
	UUE5_TestClientGameInstance* GI;
};
