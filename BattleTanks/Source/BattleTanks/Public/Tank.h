// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public: 

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Actions)
		void Fire();

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurret* TurretToSet);

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 4000; //TODO Find Sensible Default Find LaunchSpeed

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr;

	float ReloadTimeInSeconds = 3;
	double LastFireTime = 3;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UTankAimingComponent* TankAimingComponent = nullptr;
};
