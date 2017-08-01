// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const {

	
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();

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

	if (GetSightRayHitLocation(HitLocation)) {
		//TODO Start aiming toward Crosshair
	}

	UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());

	//Get Location worldspace of Linetrace through crosshair
	//If it hits the Lanscape
		//TODO Tell Controlled Tank to aim at this point

}
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocaiton) const{
	//Find Crosshair Position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D((ViewportSizeX*CrossHairXLocation), (ViewportSizeY*CrossHairYLocation));

	//TODO De-project crosshair to world a world direciton
	//TODO Raycast thought the Crosshair
	//TODO See what we hit to a max range
	
	//IF Raycast hits a location on Landscape
		//Return true
	//Else
		//Return false
	
	return true;
	
}
