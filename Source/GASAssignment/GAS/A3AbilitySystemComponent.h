// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "A3AbilitySystemComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAbilityEndDelegate);

UENUM(Blueprintable)
enum class EAbilityInputID : uint8
{
	None UMETA(DisplayName = "None"), //0
	NormalAttack UMETA(DisplayName = "Normal Attack"), //1
	HeavyAttack UMETA(DisplayName = "Heavy Attack"), //2
	Block UMETA(DisplayName = "Block"), //3
	ToggleWeapon UMETA(DisplayName = "Toggle Weapon"), //4
	Heal UMETA(DisplayName = "Heal"), //5
	Dodge UMETA(DisplayName = "Dodge") //6
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GASASSIGNMENT_API UA3AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UA3AbilitySystemComponent();
	
	virtual void NotifyAbilityEnded(FGameplayAbilitySpecHandle Handle, UGameplayAbility* Ability,
	bool bWasCancelled) override;
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(BlueprintAssignable, BlueprintReadOnly)
	FOnAbilityEndDelegate OnAbilityEnd;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
