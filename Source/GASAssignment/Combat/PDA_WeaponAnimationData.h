// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PDA_WeaponAnimationData.generated.h"


USTRUCT(Blueprintable, BlueprintType)
struct FComboAttackData
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TObjectPtr<UAnimMontage> Montage;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (Tooltip = "Range of 0 to 1, dictates the likelihood of an AI enemy cancelling their combo after this attack. Not relevant for player controlled characters."))
	float ChanceForComboCancel;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta= (Tooltip = "Range of 0 to 1, dictates the likelihood of a succesful parry interrupting the combo."))
	float ChanceForComboInterruption;
};


UCLASS()
class GASASSIGNMENT_API UPDA_WeaponAnimationData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TObjectPtr<UAnimMontage> DrawWeaponMontage;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TObjectPtr<UAnimMontage> SheatheWeaponMontage;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TArray<FComboAttackData> ComboData;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TObjectPtr<UAnimMontage> HeavyAttackMontage;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TObjectPtr<UAnimMontage> BlockMontage;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TObjectPtr<UAnimMontage> BlockImpact;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TObjectPtr<UAnimMontage> HitImpact;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TObjectPtr<UAnimMontage> NonHitImpact;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TObjectPtr<UAnimMontage> DodgeMontage;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TObjectPtr<UAnimMontage> HealMontage;
};
