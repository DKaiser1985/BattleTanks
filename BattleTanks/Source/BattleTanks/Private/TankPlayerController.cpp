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

	AimTowardsCrosshair();

}
void ATankPlayerController::FindTank()
{
	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("Player Tank Not controlled"));
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Player Tank is %s"), *ControlledTank->GetName());
}
void ATankPlayerController::AimTowardsCrosshair() {
	FVector HitLocation; //Out Parameter

	if (GetSightRayHitLocation(HitLocation)) {
		//TODO Start aiming toward Crosshair
	}

	//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());
	
	///TODO{
		//Get Location worldspace of Linetrace through crosshair
		//If it hits the Lanscape
			//TODO Tell Controlled Tank to aim at this point}

}
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocaiton) const{
	int32 ViewportSizeX, ViewportSizeY;
	
	//Find Where crosshair lies on screen (1/3 down on Y and 1/2 across on X)
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D((ViewportSizeX*CrossHairXLocation), (ViewportSizeY*CrossHairYLocation));
	FVector LookDirection;
	
	if (GetLookDirection(ScreenLocation, LookDirection)) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *LookDirection.ToString());
	}
	
	//TODO Raycast thought the Crosshair
	//TODO See what we hit to a max range
	
	//IF Raycast hits a location on Landscape
		//Return true
	//Else
		//Return false
	
	return true;
	
}
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const{
	FVector CameraLocation; //To be Discarded
	
	//Sets LookDirection based on crosshair
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraLocation, LookDirection);
}

