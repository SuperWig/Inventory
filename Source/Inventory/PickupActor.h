// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "PickupActor.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_API APickupActor : public AInteractableActor
{
	GENERATED_BODY()

public:
	APickupActor();
	virtual void InteractWith(ABasicCharacter*) override;
	
private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere, Meta = (Bitmask, BitmaskEnum = "EItems"))
	int32 Values;
};
