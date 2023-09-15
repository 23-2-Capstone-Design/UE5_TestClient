// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PacketHeader.generated.h"

/**
 * 
 */
USTRUCT(NotBlueprintType)
struct UE5_TESTCLIENT_API FPacketHeader
{
	GENERATED_BODY()

	FPacketHeader();

	uint16 Size;
	uint16 Type;
};
