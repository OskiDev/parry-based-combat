// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

class UCapsuleComponent;
class UPDA_WeaponAnimationData;
class UPDA_WeaponBaseData;

UCLASS(Abstract, BlueprintType, Blueprintable)
class GASASSIGNMENT_API AWeapon : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWeapon();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> StaticMeshComp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UCapsuleComponent> WeaponCollision;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPDA_WeaponBaseData> WeaponBaseData;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPDA_WeaponAnimationData> WeaponAnimationData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TObjectPtr<AActor>> TraceIgnoreArray;
	
	UFUNCTION(BlueprintCallable)
	void ResetIgnoreArray();
	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void RunWeaponTrace();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
