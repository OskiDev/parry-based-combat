// Fill out your copyright notice in the Description page of Project Settings.


#include "GASBaseCharacter.h"

#include "A3GameplayAbility.h"
#include "AbilitySystemComponent.h"
#include "Combat/PDA_WeaponBaseData.h"
#include "Combat/Weapon.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AGASBaseCharacter::AGASBaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CharASC = CreateDefaultSubobject<UA3AbilitySystemComponent>(FName("CharASC"));
	
	Weapon = CreateDefaultSubobject<UChildActorComponent>("Enemy Weapon");
	Weapon->SetupAttachment(GetMesh());
}

void AGASBaseCharacter::DeathRagdoll() const
{
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	GetMesh()->SetAllBodiesBelowSimulatePhysics(FName("Hips"), true, true);
}

// Called when the game starts or when spawned
void AGASBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (CharASC)
	{
		BasicATRBSet = CharASC->GetSet<UCombatAttributeSet>();
	}
	
	for (TSubclassOf AbilityClass : StartingAbilities)
	{
		int32 InputID = -1;
		
		if (const UA3GameplayAbility* AbilityCDO = GetDefault<UA3GameplayAbility>(AbilityClass))
		{
			InputID = static_cast<int32>(AbilityCDO->AbilityInputID);
		}
		CharASC->GiveAbility(FGameplayAbilitySpec(AbilityClass, 1, InputID, this));
	}
	
	WeaponRef = Cast<AWeapon>(Weapon->GetChildActor());
	WeaponRef->SetOwner(this);
	WeaponRef->ResetIgnoreArray();
	Weapon->SetRelativeTransform_Direct(WeaponRef->WeaponBaseData->DefaultWeaponTransform);
	Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, false), WeaponRef->WeaponBaseData->DefaultSocket);
	
}

AWeapon* AGASBaseCharacter::GetOwnerWeapon()
{
	return WeaponRef.Get() ? WeaponRef : nullptr;
}

// Called every frame
void AGASBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AGASBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

