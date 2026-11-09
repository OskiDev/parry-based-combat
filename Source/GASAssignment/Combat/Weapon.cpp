// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

#include "K2Node_PlayMontage.h"
#include "PlayMontageCallbackProxy.h"
#include "Components/CapsuleComponent.h"


// Sets default values
AWeapon::AWeapon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
	StaticMeshComp->SetupAttachment(RootComponent);
	StaticMeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WeaponCollision = CreateDefaultSubobject<UCapsuleComponent>("WeaponCollision");
	WeaponCollision->SetupAttachment(StaticMeshComp);
	/*WeaponCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	WeaponCollision->SetCollisionObjectType(ECC_GameTraceChannel1);
	WeaponCollision->SetCollisionResponseToAllChannels(ECR_Overlap);
	WeaponCollision->SetCollisionProfileName("CollisionEnabled");*/
}

void AWeapon::ResetIgnoreArray()
{
	TraceIgnoreArray.Empty(4);
	TraceIgnoreArray.Add(GetOwner());
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

