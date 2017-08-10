// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	if (!BarrelToSet) { return; } //protect Pointers
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	if (!TurretToSet) { return; } //protect Pointers
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (Barrel == nullptr||Turret == nullptr) {
		
		auto ThisTank = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s Barrel is NULL"), *ThisTank);
		return;
	}
	
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Socket"));

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLocation, LaunchSpeed, false, 0.0, 0.0, ESuggestProjVelocityTraceOption::DoNotTrace);
	
	if(bHaveAimSolution){
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
	else {
		//No Aim Solution, do nothing
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {
	//Find Barrel's current Position
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator TurretRotator = Turret->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();

	//Find the difference between current Position and hit locaiton
	FRotator DeltaRotator = AimAsRotator - BarrelRotator;
	
	Barrel->Elevate(DeltaRotator.Pitch);//Move the barrel with Pitch Based on crosshair
	Turret->Rotate(DeltaRotator.Yaw);

}