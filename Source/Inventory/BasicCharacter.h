// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Items.h"
#include "GameFramework/Character.h"
#include "BasicCharacter.generated.h"

UCLASS()
class INVENTORY_API ABasicCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABasicCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable)
	int32 GetInventory() const { return Inventory; }
	void Add(int32 Item);

protected:
	virtual void BeginPlay() override;

private:
	void RedKey();
	void BlueKey();
	void Dinosaur();
	void AddAll();
	
	void MoveForwards(float Value);
	void MoveRight(float Value);
	void Action();

	UPROPERTY(VisibleAnywhere, Meta = (Bitmask, BitmaskEnum = "EItems"))
	int32 Inventory; 
};
