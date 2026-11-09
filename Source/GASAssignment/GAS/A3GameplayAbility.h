// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "A3GameplayAbility.generated.h"

enum class EAbilityInputID : uint8;
/**
 * 
 */
UCLASS(Abstract)
class GASASSIGNMENT_API UA3GameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Ability")
	EAbilityInputID AbilityInputID;
};
