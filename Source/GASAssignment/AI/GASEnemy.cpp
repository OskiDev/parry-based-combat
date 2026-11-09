// Fill out your copyright notice in the Description page of Project Settings.


#include "GASEnemy.h"

#include "Combat/PDA_WeaponBaseData.h"
#include "Combat/Weapon.h"


// Sets default values
AGASEnemy::AGASEnemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGASEnemy::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGASEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AGASEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

