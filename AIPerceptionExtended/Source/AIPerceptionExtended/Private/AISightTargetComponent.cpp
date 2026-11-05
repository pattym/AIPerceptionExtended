// Fill out your copyright notice in the Description page of Project Settings.


#include "AISightTargetComponent.h"


// Sets default values for this component's properties
UAISightTargetComponent::UAISightTargetComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UAISightTargetComponent::BeginPlay()
{
	Super::BeginPlay();
}
void UAISightTargetComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                            FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

UAISense_Sight::EVisibilityResult UAISightTargetComponent::CanBeSeenFrom(const FCanBeSeenFromContext& Context,	FVector& OutSeenLocation, int32& NumberOfLoSChecksPerformed, int32& NumberOfAsyncLosCheckRequested, float& OutSightStrength, int32* UserData, const FOnPendingVisibilityQueryProcessedDelegate* Delegate)
{
	NumberOfLoSChecksPerformed = 0;
	NumberOfAsyncLosCheckRequested = 0;
	OutSightStrength = 0.0f;

	if (!IsValid(Strategy))
	{
		return UAISense_Sight::EVisibilityResult::NotVisible;
	}

	const bool bWasVisible = Context.bWasVisible != nullptr && *Context.bWasVisible;

	const bool bCanBeSeen = Strategy->CanBeSeenFrom(
		GetOwner(),
		Context.ObserverLocation,
		Context.IgnoreActor,
		bWasVisible,
		OutSeenLocation,
		OutSightStrength,
		NumberOfLoSChecksPerformed
	);
	return bCanBeSeen ? UAISense_Sight::EVisibilityResult::Visible : UAISense_Sight::EVisibilityResult::NotVisible;
}

void UAISightTargetComponent::SetStrategyClass(const TSubclassOf<UAISightTargetStrategy> StrategyClass)
{
	if (!StrategyClass)
	{
		Strategy = nullptr;
		return;
	}

	Strategy = NewObject<UAISightTargetStrategy>(this,StrategyClass);
}


