// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PDA_WeaponBaseData.generated.h"

/**
 * 
 */
UCLASS()
class GASASSIGNMENT_API UPDA_WeaponBaseData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int LowerHealthDamageRange;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int UpperHealthDamageRange;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int LowerPostureDamageRange;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int UpperPostureDamageRange;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FTransform DefaultWeaponTransform;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FTransform HeldWeaponTransform;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FName DefaultSocket;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FName HeldSocket;
};
