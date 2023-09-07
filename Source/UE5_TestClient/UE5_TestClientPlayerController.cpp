// Fill out your copyright notice in the Description page of Project Settings.


#include "UE5_TestClientPlayerController.h"

AUE5_TestClientPlayerController::AUE5_TestClientPlayerController()
{
	// TODO Edit Ref Path
	/*static ConstructorHelpers::FObjectFinder<UClientSession> ClientSessionRef(
		TEXT("/Script/CoreUObject.Class'/Script/UE5_TestClient.ClientSession'"));
	if (ClientSessionRef.Object)
	{
		Session = ClientSessionRef.Object;
	}*/

	Session = NewObject<UClientSession>();

	PrimaryActorTick.bCanEverTick = true;
}

AUE5_TestClientPlayerController::~AUE5_TestClientPlayerController()
{
}

void AUE5_TestClientPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AUE5_TestClientPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (Session->InitSocket() == false)
	{
		return;
	}

	if (Session->Connect() == false)
	{
		return;
	}

	if (Session->IsConnected())
	{
		Session->RunThread();
		if (Session->IsThreadRunning() == false)
		{
			UE_LOG(LogTemp, Log, TEXT("RunThread Error"));
		}
	}
}
