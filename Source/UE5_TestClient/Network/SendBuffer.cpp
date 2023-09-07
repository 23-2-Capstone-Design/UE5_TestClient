// Fill out your copyright notice in the Description page of Project Settings.


#include "SendBuffer.h"

SendBuffer::SendBuffer(uint32 BufferSize)
{
	Buffer.Init(0, BufferSize);
}
