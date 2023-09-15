// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Protocol/Packet.pb.h"
#include "SendBuffer.h"
#include "PacketHeader.h"
#include "../UE5_TestClientGameInstance.h"

class UClientSession;

/**
 * 
 */
class UE5_TESTCLIENT_API ServerPacketHandler
{
public:
	static void HandlePacket(UClientSession* Session, char* Buffer, int32 NumOfBytes)
	{
		// TODO Interface
		UUE5_TestClientGameInstance* Instance = Cast<UUE5_TestClientGameInstance>(Session->GetGameInstance());
		FPacketHeader* Header = reinterpret_cast<FPacketHeader*>(Buffer);

		Instance->GetPacketQueueRef().Enqueue(Header);
	}

private:
	template <typename T>
	static USendBuffer* MakeSendBuffer(T& Packet, protocol::PacketType PacketType)
	{
		const uint16 DataSize = static_cast<uint16>(Packet.ByteSizeLong());
		const uint16 PacketSize = DataSize + sizeof(FPacketHeader);

		USendBuffer* Buffer = NewObject<USendBuffer>();
		Buffer->SetSize(PacketSize);
		FPacketHeader* Header = reinterpret_cast<FPacketHeader*>(Buffer->GetBuffer());
		Header->Size = PacketSize;
		Header->Type = PacketType;

		Packet.SerializeToArray(&Header[1], DataSize);

		return Buffer;
	}

public:
	static USendBuffer* MakeSendBuffer(protocol::C_JOIN& Packet)
	{
		return MakeSendBuffer(Packet, protocol::PT_C_JOIN);
	}

	static USendBuffer* MakeSendBuffer(protocol::C_LEAVE& Packet)
	{
		return MakeSendBuffer(Packet, protocol::PT_C_LEAVE);
	}

	static USendBuffer* MakeSendBuffer(protocol::C_MOVE& Packet)
	{
		return MakeSendBuffer(Packet, protocol::PT_C_MOVE);
	}
};
