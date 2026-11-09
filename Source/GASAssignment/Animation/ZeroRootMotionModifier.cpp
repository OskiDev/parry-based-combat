// Fill out your copyright notice in the Description page of Project Settings.


#include "ZeroRootMotionModifier.h"

void UZeroRootMotionModifier::OnApply_Implementation(UAnimSequence* AnimationSequence)
{
	if (!AnimationSequence) return;

	const USkeleton* Skeleton = AnimationSequence->GetSkeleton();
	if (!Skeleton) return;

	const FName RootBoneName = Skeleton->GetReferenceSkeleton().GetBoneName(0);

	const IAnimationDataModel* Model = AnimationSequence->GetDataModel();
	if (!Model || !Model->IsValidBoneTrackName(RootBoneName))
	{
		UE_LOG(LogAnimation, Warning, TEXT("Root bone track not found: %s"), *RootBoneName.ToString());
		return;
	}

	TArray<FVector3f> PosKeys;
	TArray<FQuat4f> RotKeys;
	TArray<FVector3f> ScaleKeys;

	Model->IterateBoneKeys(RootBoneName, [&PosKeys, &RotKeys, &ScaleKeys](const FVector3f& Pos, const FQuat4f& Rot, const FVector3f Scale, const FFrameNumber&)
	{
		PosKeys.Add(FVector3f(0.f, 0.f, Pos.Z));
		RotKeys.Add(Rot);
		ScaleKeys.Add(Scale);
		return true;
	});

	IAnimationDataController& Controller = AnimationSequence->GetController();
	Controller.OpenBracket(FText::FromString("Zero Root Motion"));
	Controller.SetBoneTrackKeys(RootBoneName, PosKeys, RotKeys, ScaleKeys);
	Controller.CloseBracket();
}