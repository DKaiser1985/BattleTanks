// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const {

	
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("This is Ticking"));
	//TODO AimTowardCrosshair();

}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	
	if (!ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("Player Tank Not controlled"));
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Player Tank is %s"), *ControlledTank->GetName());

}
