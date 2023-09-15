// Fill out your copyright notice in the Description page of Project Settings.


#include "UE5_TestClientGameInstance.h"
#include "Network/ServerPacketHandler.h"

void UUE5_TestClientGameInstance::Init()
{
	Super::Init();

	ServerPacketHandler::Init();

	Session = NewObject<UClientSession>();

	if (Session->InitSocket() == false)
	{
		return;
	}

	if (Session->Connect() == false)
	{
		return;
	}

	Session->SetGameInstance(this);

	if (Session->IsConnected())
	{
		Session->RunThread();
		if (Session->IsThreadRunning() == false)
		{
			UE_LOG(LogTemp, Log, TEXT("RunThread Error"));
		}
	}
}
