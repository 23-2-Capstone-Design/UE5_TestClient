// Fill out your copyright notice in the Description page of Project Settings.


#include "RecvBuffer.h"

RecvBuffer::RecvBuffer()
	: WritePosition(0), ReadPosition(0)
{
	Buffer.Init(0, MAX_BUFFER_SIZE);
}

void RecvBuffer::CleanupBuffer()
{
	if (WritePosition == ReadPosition)
	{
		WritePosition = ReadPosition = 0;
		return;
	}

	if (GetFreeSize() <= MIN_BUFFER_SIZE)
	{
		const uint32 DataSize = GetDataSize();
		FMemory::Memcpy(Buffer.GetData(), GetReadBufferPos(), DataSize);
		ReadPosition = 0;
		WritePosition = DataSize;
	}
}

bool RecvBuffer::WriteData(int32 Size)
{
	if (GetFreeSize() < Size)
	{
		return false;
	}

	WritePosition += Size;
	return true;
}

bool RecvBuffer::ReadData(int32 Size)
{
	if (GetDataSize() < Size)
	{
		return false;
	}

	ReadPosition += Size;
	return true;
}
