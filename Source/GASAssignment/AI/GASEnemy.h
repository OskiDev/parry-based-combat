// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Combat/CombatInterface.h"
#include "GAS/GASBaseCharacter.h"
#include "GASEnemy.generated.h"

class AWeapon;

UCLASS()
class GASASSIGNMENT_API AGASEnemy : public AGASBaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGASEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
