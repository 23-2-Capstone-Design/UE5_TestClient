// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SendBuffer.generated.h"

/**
 * 
 */
UCLASS()
class UE5_TESTCLIENT_API USendBuffer : public UObject
{
	GENERATED_BODY()
public:
	USendBuffer();

public:
	void SetSize(uint16 BufferSize);
	char* GetBuffer() { return Buffer.GetData(); }
	uint16 GetSize() { return Size; }

protected:
	TArray<char> Buffer;
	uint16 Size;
};
