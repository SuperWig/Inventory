// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupActor.h"

#include "BasicCharacter.h"

APickupActor::APickupActor()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
}

void APickupActor::InteractWith(ABasicCharacter* Character)
{
	Character->Add(Values);
	SetLifeSpan(0.5f);
}
