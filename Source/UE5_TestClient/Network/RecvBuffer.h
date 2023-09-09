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
	int32 GetDataSize() const { return WritePosition - ReadPosition; }
	int32 GetFreeSize() const { return MAX_BUFFER_SIZE - WritePosition; }
	char* GetWriteBufferPos() { return Buffer.GetData() + WritePosition; }
	char* GetReadBufferPos() { return Buffer.GetData() + ReadPosition; }

public:
	void CleanupBuffer();
	bool WriteData(int32 Size);
	bool ReadData(int32 Size);

protected:
	TArray<char> Buffer;
	int32 WritePosition;
	int32 ReadPosition;
};
