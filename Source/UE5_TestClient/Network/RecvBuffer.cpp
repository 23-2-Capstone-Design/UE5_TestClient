// Fill out your copyright notice in the Description page of Project Settings.


#include "RecvBuffer.h"

RecvBuffer::RecvBuffer()
	: Head(0), Tail(0)
{
	Buffer.Init(0, MAX_BUFFER_SIZE);
}

void RecvBuffer::CleanupBuffer()
{
	if(Head == Tail)
	{
		Head = Tail = 0;
		return;
	}

	if(GetFreeSize() <= MIN_BUFFER_SIZE)
	{
		const uint32 DataSize = GetDataSize();
		FMemory::Memcpy(Buffer.GetData(), GetBufferTail(), DataSize);
		Tail = 0;
		Head = DataSize;
	}
}

bool RecvBuffer::WriteData(uint32 Size)
{
	if (GetFreeSize() < Size)
	{
		return false;
	}

	Head += Size;
	return true;
}

bool RecvBuffer::ReadData(uint32 Size)
{
	if (GetDataSize() < Size)
	{
		return false;
	}

	Tail += Size;
	return true;
}

