// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5_TestClientGameMode.h"
#include "UE5_TestClientCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5_TestClientGameMode::AUE5_TestClientGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
