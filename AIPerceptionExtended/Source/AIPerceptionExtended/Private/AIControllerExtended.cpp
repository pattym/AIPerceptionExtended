// Fill out your copyright notice in the Description page of Project Settings.


#include "AIControllerExtended.h"


// Sets default values
AAIControllerExtended::AAIControllerExtended()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAIControllerExtended::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAIControllerExtended::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAIControllerExtended::UpdateControlRotation(float DeltaTime, bool bUpdatePawn)
{
	//Super::UpdateControlRotation(DeltaTime, bUpdatePawn);

	if (APawn* const MyPawn = GetPawn())
	{
		FRotator NewControlRotation = GetControlRotation();

		// Look toward focus
		if (const FVector FocalPoint = GetFocalPoint(); FAISystem::IsValidLocation(FocalPoint))
		{
			NewControlRotation = (FocalPoint - MyPawn->GetPawnViewLocation()).Rotation();
		}
		else if (bSetControlRotationFromPawnOrientation)
		{
			NewControlRotation = MyPawn->GetActorRotation();
		}
		
		if (bIgnoreFocusPitch)
		{
			// Don't pitch view unless looking at another pawn
            if (NewControlRotation.Pitch != 0 && Cast<APawn>(GetFocusActor()) == nullptr)
            {
            	NewControlRotation.Pitch = 0.f;
            }
		}
		
		SetControlRotation(NewControlRotation);

		if (bUpdatePawn)
		{
			const FRotator CurrentPawnRotation = MyPawn->GetActorRotation();

			if (CurrentPawnRotation.Equals(NewControlRotation, 1e-3f) == false)
			{
				MyPawn->FaceRotation(NewControlRotation, DeltaTime);
			}
		}
	}
}

