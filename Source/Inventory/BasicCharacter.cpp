// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicCharacter.h"

#include <type_traits>



#include "InteractableActor.h"
#include "Items.h"

// Sets default values
ABasicCharacter::ABasicCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABasicCharacter::Add(int32 Item)
{
	Inventory |= Item;
	UE_LOG(LogTemp, Warning, TEXT("Player has %d"), Inventory)
}

// Called when the game starts or when spawned
void ABasicCharacter::BeginPlay()
{
	Super::BeginPlay();

	//EnumAddFlags(Inventory, EItems::RedKey);
	
}

// Called every frame
void ABasicCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasicCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABasicCharacter::MoveForwards);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABasicCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ACharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookRight", this, &ACharacter::AddControllerYawInput);

	PlayerInputComponent->BindAction("Action", IE_Pressed, this, &ABasicCharacter::Action);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("ToggleRedKey", IE_Pressed, this, &ABasicCharacter::RedKey);
	PlayerInputComponent->BindAction("ToggleBlueKey", IE_Pressed, this, &ABasicCharacter::BlueKey);
	PlayerInputComponent->BindAction("ToggleDinosaur", IE_Pressed, this, &ABasicCharacter::Dinosaur);
	PlayerInputComponent->BindAction("AddAll", IE_Pressed, this, &ABasicCharacter::AddAll);
}

void ABasicCharacter::RedKey()
{
	ToggleItems(Inventory, EItems::RedKey);
	UE_LOG(LogTemp, Warning, TEXT("Player has %d"), Inventory)
}

void ABasicCharacter::BlueKey()
{
	ToggleItems(Inventory, EItems::BlueKey);
	UE_LOG(LogTemp, Warning, TEXT("Player has %d"), Inventory)
}

void ABasicCharacter::Dinosaur()
{
	ToggleItems(Inventory, EItems::Dinosaur);
	UE_LOG(LogTemp, Warning, TEXT("Player has %d"), Inventory)
}

void ABasicCharacter::AddAll()
{
	AddItems(Inventory, EItems::RedKey | EItems::BlueKey | EItems::Dinosaur);
}

void ABasicCharacter::MoveForwards(float Value)
{
	if (Value != 0.f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void ABasicCharacter::MoveRight(float Value)
{
	if (Value != 0.f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}	
}

void ABasicCharacter::Action()
{
	FVector Start;
	FRotator Direction;
	GetController()->GetPlayerViewPoint(Start, Direction);
	const FVector End = Start + Direction.Vector() * 500.f;

	const static FName Tag = "Tag";
	GetWorld()->DebugDrawTraceTag = Tag;
	FCollisionQueryParams Params(Tag, false, this);
	
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Camera, Params);
	if (auto* Actor = Cast<AInteractableActor>(HitResult.GetActor()))
	{
		Actor->InteractWith(this);
	}

	
}