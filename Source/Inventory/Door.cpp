// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

#include "BasicCharacter.h"
#include "Items.h"

ADoor::ADoor()
{
	DummyRoot = CreateDefaultSubobject<USceneComponent>("Dummy");
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>("DoorMesh");

	RootComponent = DummyRoot;
	DoorMesh->SetupAttachment(DummyRoot);
}

void ADoor::InteractWith(ABasicCharacter* Character)
{
	const int32 Inv = Character->GetInventory();
	const bool bHasKey = (UnlockedWith & Inv) == UnlockedWith;
	const FColor SuccessColor = bHasKey ? FColor::Green : FColor::Red;
	GEngine->AddOnScreenDebugMessage(0, 1.f, SuccessColor, FString::Printf(TEXT("Player has keys needed: %s"), bHasKey ? TEXT("true") : TEXT("false")));
}

void ADoor::BeginPlay()
{
	//EnumHasAnyFlags(UnlockedWith)
	UE_LOG(LogTemp, Warning, TEXT("UnlockedWith: %d"), UnlockedWith)
}
