// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Protocol/Packet.pb.h"
#include "SendBuffer.h"
#include <functional>

class UClientSession;
using PacketHandlerFunc = TFunction<bool(UClientSession*, char*, int32)>;
extern PacketHandlerFunc GPacketHandler[UINT16_MAX];

struct UE5_TESTCLIENT_API PacketHeader
{
	uint16 Size;
	protocol::PacketType Type;
};

bool Handle_Invalid(class UClientSession* Session, char* Buffer, int32 NumOfBytes);
bool Handle_S_JOIN(class UClientSession* Session, protocol::S_JOIN& Packet);
bool Handle_S_LEAVE(class UClientSession* Session, protocol::S_LEAVE& Packet);
bool Handle_S_MOVE(class UClientSession* Session, protocol::S_MOVE& Packet);

/**
 * 
 */
class UE5_TESTCLIENT_API ServerPacketHandler
{
	enum
	{
		HANDLER_SIZE = 10000
	};

public:
	static void Init()
	{
		for (int32 i = 0; i < UINT16_MAX; i++)
		{
			GPacketHandler[i] = Handle_Invalid;
		}
		GPacketHandler[protocol::PT_S_JOIN] = [](UClientSession* Session, char* Buffer, int32 NumOfBytes)
		{
			return HandlePacket<protocol::S_JOIN>(Handle_S_JOIN, Session, Buffer, NumOfBytes);
		};
		GPacketHandler[protocol::PT_S_LEAVE] = [](UClientSession* Session, char* Buffer, int32 NumOfBytes)
		{
			return HandlePacket<protocol::S_LEAVE>(Handle_S_LEAVE, Session, Buffer, NumOfBytes);
		};
		GPacketHandler[protocol::PT_S_MOVE] = [](UClientSession* Session, char* Buffer, int32 NumOfBytes)
		{
			return HandlePacket<protocol::S_MOVE>(Handle_S_MOVE, Session, Buffer, NumOfBytes);
		};
	}

	static bool HandlePacket(UClientSession* Session, char* Buffer, int32 NumOfBytes)
	{
		PacketHeader* Header = reinterpret_cast<PacketHeader*>(Buffer);
		return GPacketHandler[Header->Type](Session, Buffer, NumOfBytes);
	}

	static SendBuffer MakeSendBuffer(protocol::C_MOVE& Packet) { return MakeSendBuffer(Packet, protocol::PT_S_MOVE); }

private:
	template <typename PacketType, typename ProcessFunc>
	static bool HandlePacket(ProcessFunc Func, UClientSession* Session, char* Buffer, int32 NumOfBytes)
	{
		PacketType Packet;
		return Func(Session, Packet);
	}

	template <typename T>
	static SendBuffer MakeSendBuffer(T& Packet, protocol::PacketType PacketType)
	{
		const uint16 DataSize = static_cast<uint16>(Packet.ByteSizeLong());
		const uint16 PacketSize = DataSize + sizeof(PacketHeader);

		SendBuffer Buffer(PacketSize);
		PacketHeader* Header = reinterpret_cast<PacketHeader*>(Buffer.GetBuffer());
		Header->Size = PacketSize;
		Header->Type = PacketType;

		Packet.SerializeToArray(&Header[1], DataSize);

		return Buffer;
	}
};
