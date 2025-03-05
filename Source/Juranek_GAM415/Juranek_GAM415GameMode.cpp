// Copyright Epic Games, Inc. All Rights Reserved.

#include "Juranek_GAM415GameMode.h"
#include "Juranek_GAM415Character.h"
#include "UObject/ConstructorHelpers.h"

AJuranek_GAM415GameMode::AJuranek_GAM415GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
