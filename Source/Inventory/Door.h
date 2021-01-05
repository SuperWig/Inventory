// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "Items.h"

#include "Door.generated.h"

UCLASS()
class INVENTORY_API ADoor : public AInteractableActor
{
	GENERATED_BODY()

public:
	ADoor();

	virtual void InteractWith(ABasicCharacter*) override;
	
protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* DummyRoot;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* DoorMesh;
	UPROPERTY(EditAnywhere ,Meta = (Bitmask, BitmaskEnum = "EItems"))
	int32 UnlockedWith;
	
};
