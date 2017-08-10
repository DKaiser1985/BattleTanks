// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed) {
	
	//Rotate Barrel by the correct ammount this frame to the AimDirection by some distance per second
	auto Time = GetWorld()->GetRealTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Tank Elevate"), Time);
}


