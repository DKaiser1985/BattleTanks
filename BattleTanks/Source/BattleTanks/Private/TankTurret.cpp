// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	//Clamp the speed to ±100% of the value MaxDegreePerSecond
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, +1.0f);

	///Calculate yaw change based on time not frames as to be framerate independent
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + ElevationChange;

	//Move the barrel Per frame
	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}
