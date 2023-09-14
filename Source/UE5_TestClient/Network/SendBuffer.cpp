// Fill out your copyright notice in the Description page of Project Settings.


#include "SendBuffer.h"

USendBuffer::USendBuffer()
{
}

void USendBuffer::SetSize(uint16 BufferSize)
{
	Size = BufferSize;
	Buffer.Init(0, Size);
}
