// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Movement)
		void SetThrottle(float Throttle);
	
	UPROPERTY(EditDefaultsOnly) //Max Force to be applied by track in Newtons F = M*a
		float TrackMaxDrivingForce = 4000000; //TODO Find Resonable Default
	
};
