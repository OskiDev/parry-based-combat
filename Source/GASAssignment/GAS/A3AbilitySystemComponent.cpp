// Fill out your copyright notice in the Description page of Project Settings.


#include "A3AbilitySystemComponent.h"


void UA3AbilitySystemComponent::NotifyAbilityEnded(FGameplayAbilitySpecHandle Handle, UGameplayAbility* Ability,
	bool bWasCancelled)
{
	Super::NotifyAbilityEnded(Handle, Ability, bWasCancelled);
}

// Sets default values for this component's properties
UA3AbilitySystemComponent::UA3AbilitySystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UA3AbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
	
	OnAbilityEnded.AddLambda([this](const FAbilityEndedData& Data)
	{
		OnAbilityEnd.Broadcast();
	});
}


// Called every frame
void UA3AbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                              FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

