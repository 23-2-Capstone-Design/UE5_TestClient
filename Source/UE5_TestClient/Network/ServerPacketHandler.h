// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Protocol/Packet.pb.h"
#include "SendBuffer.h"
#include "PacketHeader.h"
#include "../UE5_TestClientGameInstance.h"

class UClientSession;
//using PacketHandlerFunc = TFunction<bool(UClientSession*, char*, int32)>;
//extern PacketHandlerFunc GPacketHandler[UINT16_MAX];

//bool Handle_Invalid(class UClientSession* Session, char* Buffer, int32 NumOfBytes);
//bool Handle_S_JOIN(class UClientSession* Session, protocol::S_JOIN& Packet);
//bool Handle_S_LEAVE(class UClientSession* Session, protocol::S_LEAVE& Packet);
//bool Handle_S_MOVE(class UClientSession* Session, protocol::S_MOVE& Packet);

/**
 * 
 */
class UE5_TESTCLIENT_API ServerPacketHandler
{
public:
	static void Init()
	{
	}

	static bool HandlePacket(UClientSession* Session, char* Buffer, int32 NumOfBytes)
	{
		// TODO Interface
		UUE5_TestClientGameInstance* Instance = Cast<UUE5_TestClientGameInstance>(Session->GetGameInstance());
		FPacketHeader* Header = reinterpret_cast<FPacketHeader*>(Buffer);
		Instance->GetPacketQueueRef().Enqueue(Header);
		return true;
		//return GPacketHandler[Header->Type](Session, Buffer, NumOfBytes);
	}

private:
	template <typename PacketType, typename ProcessFunc>
	static bool HandlePacket(ProcessFunc Func, UClientSession* Session, char* Buffer, int32 NumOfBytes)
	{
		PacketType Packet;
		if (Packet.ParseFromArray(buffer + sizeof(FPacketHeader), NumOfBytes - sizeof(FPacketHeader)) == false)
		{
			return false;
		}
		return Func(Session, Packet);
	}

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
