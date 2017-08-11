// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;

	void FindTank();

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	UPROPERTY(EditDefaultsOnly) float CrossHairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly) float CrossHairYLocation = 0.3333;
	//Max Ray Trace in cm
	UPROPERTY(EditDefaultsOnly) float LineTraceRange = 1000000;
	
		//Called Every Frame
	virtual void Tick(float DeltaTime) override;
};
