// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableActor.generated.h"

class ABasicCharacter;
UCLASS(Abstract)
class INVENTORY_API AInteractableActor : public AActor
{
	GENERATED_BODY()
	
public:
	virtual void InteractWith(ABasicCharacter*) PURE_VIRTUAL(InteractWith,)
};
