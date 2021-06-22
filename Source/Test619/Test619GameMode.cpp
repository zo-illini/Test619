// Copyright Epic Games, Inc. All Rights Reserved.

#include "Test619GameMode.h"
#include "Test619Character.h"
#include "UObject/ConstructorHelpers.h"

ATest619GameMode::ATest619GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
