// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AISightTargetStrategy.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable, EditInlineNew, DefaultToInstanced)
class AIPERCEPTIONEXTENDED_API UAISightTargetStrategy : public UObject
{
	GENERATED_BODY()

public:
	virtual UWorld* GetWorld() const override;

	UFUNCTION(BlueprintNativeEvent, Category="AI|Sight")
	bool CanBeSeenFrom(AActor* TargetActor,	FVector ObserverLocation, const AActor* IgnoreActor, bool bWasVisible, FVector& OutSeenLocation, float& OutSightStrength, int32& OutNumberOfLoSChecksPerformed);
};