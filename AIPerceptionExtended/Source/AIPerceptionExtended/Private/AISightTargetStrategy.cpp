#include "AISightTargetStrategy.h"

bool UAISightTargetStrategy::CanBeSeenFrom_Implementation(AActor* TargetActor, FVector ObserverLocation, const AActor* IgnoreActor, bool bWasVisible, FVector& OutSeenLocation, float& OutSightStrength, int32& OutNumberOfLoSChecksPerformed)
{
	OutSightStrength = 0.0f;
	OutNumberOfLoSChecksPerformed = 0;

	return false;
}

class UWorld* UAISightTargetStrategy::GetWorld() const
{
	if (IsTemplate() || !GetOuter()) // We're the CDO or have no outer (?!).
	{
		return nullptr;
	}
	return GetOuter()->GetWorld();
}
