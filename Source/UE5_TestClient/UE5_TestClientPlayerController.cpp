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

	/*
	Session = NewObject<UClientSession>();
	*/
}

AUE5_TestClientPlayerController::~AUE5_TestClientPlayerController()
{
}

void AUE5_TestClientPlayerController::BeginPlay()
{
	Super::BeginPlay();
}
