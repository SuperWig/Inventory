// Copyright Epic Games, Inc. All Rights Reserved.


#include "InventoryGameModeBase.h"
#include "BasicCharacter.h"

AInventoryGameModeBase::AInventoryGameModeBase()
{
	DefaultPawnClass = ABasicCharacter::StaticClass();
}
