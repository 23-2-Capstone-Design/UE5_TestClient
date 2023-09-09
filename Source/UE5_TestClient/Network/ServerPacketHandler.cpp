// Fill out your copyright notice in the Description page of Project Settings.


#include "ServerPacketHandler.h"

PacketHandlerFunc GPacketHandler[UINT16_MAX];

bool Handle_Invalid(UClientSession* Session, char* Buffer, int32 NumOfBytes)
{
	return false;
}

bool Handle_S_JOIN(UClientSession* Session, protocol::S_JOIN& Packet)
{
	UE_LOG(LogTemp, Log, TEXT("Handle S JOIN %d"), Packet.id());
	return true;
}

bool Handle_S_LEAVE(UClientSession* Session, protocol::S_LEAVE& Packet)
{
	return true;
}

bool Handle_S_MOVE(UClientSession* Session, protocol::S_MOVE& Packet)
{
	return true;
}
