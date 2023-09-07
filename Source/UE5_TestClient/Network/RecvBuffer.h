// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class UE5_TESTCLIENT_API RecvBuffer
{
	enum
	{
		MIN_BUFFER_SIZE = 0x1000,
		MAX_BUFFER_SIZE = 0x10000
	};

public:
	RecvBuffer();

public:
	uint32 GetDataSize() const { return Head - Tail; }
	uint32 GetFreeSize() const { return MAX_BUFFER_SIZE - Head; }
	char* GetBufferHead() { return Buffer.GetData() + Head; }
	char* GetBufferTail() { return Buffer.GetData() + Tail; }

public:
	void CleanupBuffer();
	bool WriteData(uint32 Size);
	bool ReadData(uint32 Size);

protected:
	TArray<char> Buffer;
	uint32 Head;
	uint32 Tail;
};
