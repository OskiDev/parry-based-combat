// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "CombatAttributeSet.generated.h"

#define ATRB_ACCESS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class GASASSIGNMENT_API UCombatAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UCombatAttributeSet();
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Health;
	ATRB_ACCESS(UCombatAttributeSet, Health);
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData MaxHealth;
	ATRB_ACCESS(UCombatAttributeSet, MaxHealth);
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Posture;
	ATRB_ACCESS(UCombatAttributeSet, Posture);
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData MaxPosture;
	ATRB_ACCESS(UCombatAttributeSet, MaxPosture);
	
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
};
