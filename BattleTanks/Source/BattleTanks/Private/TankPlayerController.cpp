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
	//TODO AimTowardsCrosshair();

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

	AimTowardsCrosshair();

}
void ATankPlayerController::AimTowardsCrosshair() {
	FVector HitLocation; //Out Parameter
	UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"),*HitLocation.ToString());

	if (GetSightRayHitLocation(HitLocation)) {
		//Start aiming toward Crosshair
	}

	UE_LOG(LogTemp, Warning, TEXT("Hit Location is now: %s"), *HitLocation.ToString());

	//Get Location worldspace of Linetrace through crosshair
	//If it hits the Lanscape
		//TODO Tell Controlled Tank to aim at this point

}
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocaiton) const{
	FVector a =	FVector(0.0f, 0.0f, 3.6f);
	OutHitLocaiton = a;
	
	//TODO GetRaySightHitLocation implementation
	
	//Raycast thought the Crosshair
	//IF Raycast hits a location on Landscape
		//Return true
	//Else
		//Return false
	
	return true;
	
}
