// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AISightTargetStrategy.h"
#include "Components/ActorComponent.h"
#include "Perception/AISightTargetInterface.h"
#include "AISightTargetComponent.generated.h"


UCLASS(BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AIPERCEPTIONEXTENDED_API UAISightTargetComponent : public UActorComponent, public IAISightTargetInterface
{
	GENERATED_BODY()

public:
	UAISightTargetComponent();
	
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadOnly, Category="AI|Sight")
	TObjectPtr<UAISightTargetStrategy> Strategy;

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	virtual UAISense_Sight::EVisibilityResult CanBeSeenFrom(const FCanBeSeenFromContext& Context,FVector& OutSeenLocation,int32& NumberOfLoSChecksPerformed,int32& NumberOfAsyncLosCheckRequested,float& OutSightStrength,int32* UserData = nullptr,const FOnPendingVisibilityQueryProcessedDelegate* Delegate = nullptr) override;
	
	UFUNCTION(BlueprintCallable, Category="AI|Sight")
	void SetStrategyClass(TSubclassOf<UAISightTargetStrategy> StrategyClass);

};
