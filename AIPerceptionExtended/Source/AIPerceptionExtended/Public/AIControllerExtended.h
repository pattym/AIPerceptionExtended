// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIControllerExtended.generated.h"

UCLASS()
class AIPERCEPTIONEXTENDED_API AAIControllerExtended : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAIControllerExtended();
	
	// Should we ignore the pitch when updating rotation from focus. Be default, it would only update pitch if focusing on an actor.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIgnoreFocusPitch = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void UpdateControlRotation(float DeltaTime, bool bUpdatePawn = true) override;
};
