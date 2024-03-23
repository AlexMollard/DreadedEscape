// Copyright Epic Games, Inc. All Rights Reserved.

#include "DreadedEscapeGameMode.h"
#include "DreadedEscapeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADreadedEscapeGameMode::ADreadedEscapeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
