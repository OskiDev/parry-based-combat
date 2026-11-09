// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimationModifier.h"
#include "ZeroRootMotionModifier.generated.h"

/**
 * 
 */
UCLASS()
class GASASSIGNMENT_API UZeroRootMotionModifier : public UAnimationModifier
{
public:
	virtual void OnApply_Implementation(UAnimSequence* AnimationSequence) override;

private:
	GENERATED_BODY()
};
