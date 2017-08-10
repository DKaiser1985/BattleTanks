// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	//auto Time = GetWorld()->GetRealTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("%f: Tank Rotate"), Time);

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, +1.0f);

	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + ElevationChange;

	//Lock the Barrel to Min/Max Pitch
	//float ClammpedElevation = FMath::Clamp<float>(RawNewElevation, MinPitchDegrees, MaxPitchDegrees);

	//Move the barrel Per frame
	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}
