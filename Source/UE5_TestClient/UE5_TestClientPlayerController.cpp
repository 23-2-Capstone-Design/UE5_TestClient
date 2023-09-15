// Fill out your copyright notice in the Description page of Project Settings.


#include "UE5_TestClientPlayerController.h"
#include "Network/Protocol/Packet.pb.h"
#include "Network/ServerPacketHandler.h"

PacketHandlerFunc GPacketHandler[UINT16_MAX];

bool Handle_Invalid(UClientSession* Session, char* Buffer, int32 NumOfBytes)
{
	return false;
}

bool Handle_S_JOIN(UClientSession* Session, protocol::S_JOIN& Packet)
{
	UE_LOG(LogTemp, Log, TEXT("Handle S JOIN %d"), Packet.id());
	return true;
}

bool Handle_S_LEAVE(UClientSession* Session, protocol::S_LEAVE& Packet)
{
	UE_LOG(LogTemp, Log, TEXT("Handle S LEAVE %d"), Packet.id());
	return true;
}

bool Handle_S_MOVE(UClientSession* Session, protocol::S_MOVE& Packet)
{
	return true;
}


AUE5_TestClientPlayerController::AUE5_TestClientPlayerController()
{
	// TODO Edit Ref Path
	/*static ConstructorHelpers::FObjectFinder<UClientSession> ClientSessionRef(
		TEXT("/Script/CoreUObject.Class'/Script/UE5_TestClient.ClientSession'"));
	if (ClientSessionRef.Object)
	{
		Session = ClientSessionRef.Object;
	}*/

	/*
	Session = NewObject<UClientSession>();
	*/

	for (int32 i = 0; i < UINT16_MAX; i++)
	{
		GPacketHandler[i] = Handle_Invalid;
	}
	GPacketHandler[protocol::PT_S_JOIN] = [](UClientSession* Session, char* Buffer, int32 NumOfBytes)
		{
			return HandlePacket<protocol::S_JOIN>(Handle_S_JOIN, Session, Buffer, NumOfBytes);
		};
	GPacketHandler[protocol::PT_S_LEAVE] = [](UClientSession* Session, char* Buffer, int32 NumOfBytes)
		{
			return HandlePacket<protocol::S_LEAVE>(Handle_S_LEAVE, Session, Buffer, NumOfBytes);
		};
	GPacketHandler[protocol::PT_S_MOVE] = [](UClientSession* Session, char* Buffer, int32 NumOfBytes)
		{
			return HandlePacket<protocol::S_MOVE>(Handle_S_MOVE, Session, Buffer, NumOfBytes);
		};

	GI = nullptr;

	PrimaryActorTick.bCanEverTick = true;
}

AUE5_TestClientPlayerController::~AUE5_TestClientPlayerController()
{
}

void AUE5_TestClientPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// TODO Interface
	GI = Cast<UUE5_TestClientGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	GI->GetSession()->SetPlayerController(this);
}

void AUE5_TestClientPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UClientSession* Session = GI->GetSession();

	protocol::C_JOIN Packet;
	USendBuffer* Buffer = ServerPacketHandler::MakeSendBuffer(Packet);

	/*protocol::C_LEAVE Packet;
	Packet.set_id(1);
	USendBuffer* Buffer = ServerPacketHandler::MakeSendBuffer(Packet);*/

	Session->Send(Buffer);

	// TODO Interface
	FPacketHeader* Header = nullptr;
	while(GI->GetPacketQueueRef().Dequeue(Header))
	{
		GPacketHandler[Header->Type](Session, (char*)Header, Header->Size);
	}
	
}
