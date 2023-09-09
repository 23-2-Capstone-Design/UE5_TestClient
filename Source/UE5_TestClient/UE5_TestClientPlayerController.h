// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Network/ClientSession.h"
#include "UE5_TestClientPlayerController.generated.h"

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
};
