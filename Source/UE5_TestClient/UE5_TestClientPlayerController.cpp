// Fill out your copyright notice in the Description page of Project Settings.


#include "UE5_TestClientPlayerController.h"
#include "Network/Protocol/Packet.pb.h"
#include "Network/ServerPacketHandler.h"

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
	PrimaryActorTick.bCanEverTick = true;
}

AUE5_TestClientPlayerController::~AUE5_TestClientPlayerController()
{
}

void AUE5_TestClientPlayerController::BeginPlay()
{
	Super::BeginPlay();
	GI = Cast<UUE5_TestClientGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
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
}
