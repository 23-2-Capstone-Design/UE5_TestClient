// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class UE5_TESTCLIENT_API SendBuffer
{
public:
	SendBuffer()
	{
	}

	SendBuffer(uint32 BufferSize);

public:
	char* GetBuffer() { return Buffer.GetData(); }
	uint32 GetSize() { return Size; }

protected:
	TArray<char> Buffer;
	uint32 Size;
};
