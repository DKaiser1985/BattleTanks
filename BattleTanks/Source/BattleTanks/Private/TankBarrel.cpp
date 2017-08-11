// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed) {
	
	///Rotate Barrel by the correct ammount this frame to the AimDirection by some distance per second

	//Clamp the speed to ±100% of the value MaxDegreePerSecond
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, +1.0f);

	///Calculate elevation change based on time not frames as to be framerate independent
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	
	//Lock the Barrel to Min/Max Pitch
	float ClammpedElevation = FMath::Clamp<float>(RawNewElevation, MinPitchDegrees, MaxPitchDegrees);

	//Move the barrel Per frame
	SetRelativeRotation(FRotator(ClammpedElevation, 0, 0));

}


