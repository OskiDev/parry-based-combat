// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatAttributeSet.h"

#include "GameplayEffectExtension.h"

UCombatAttributeSet::UCombatAttributeSet()
{
	InitHealth(500);
	InitMaxHealth(500);
	InitPosture(0);
	InitMaxPosture(100);
}

void UCombatAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		const float NewHealth = FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth());
		SetHealth(NewHealth);
		
		if (NewHealth <= 0.0f)
		{
			if (AActor* OwningActor = Data.Target.GetAvatarActor())
			{
				FGameplayEventData Payload;
				Payload.Target = OwningActor;
				UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(OwningActor, FGameplayTag::RequestGameplayTag("Combat.Event.Death"), Payload);
			}
		}
	}
	
	if (Data.EvaluatedData.Attribute == GetPostureAttribute())
	{
		const float NewPosture = FMath::Clamp(GetPosture(), 0.0f, GetMaxPosture());
		SetPosture(NewPosture);
		
		if (NewPosture >= GetMaxPosture())
		{
			if (AActor* OwningActor = Data.Target.GetAvatarActor())
			{
				FGameplayEventData Payload;
				Payload.Target = OwningActor;
				UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(OwningActor, FGameplayTag::RequestGameplayTag("Combat.Event.PostureBroken"), Payload);
			}
		}
	}
}
