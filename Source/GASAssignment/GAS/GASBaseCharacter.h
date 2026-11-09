// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "A3AbilitySystemComponent.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "CombatAttributeSet.h"
#include "Combat/CombatInterface.h"
#include "GASBaseCharacter.generated.h"

UCLASS()
class GASASSIGNMENT_API AGASBaseCharacter : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGASBaseCharacter();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return CharASC;
	}
	
	UFUNCTION(BlueprintCallable)
	void DeathRagdoll() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UA3AbilitySystemComponent> CharASC;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	const UCombatAttributeSet* BasicATRBSet;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<UGameplayAbility>> StartingAbilities;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UChildActorComponent> Weapon;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<AWeapon> WeaponRef;

	virtual AWeapon* GetOwnerWeapon() override;
};
