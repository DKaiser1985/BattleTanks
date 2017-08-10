// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (Barrel == nullptr) {
		
		auto ThisTank = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s Barrel is NULL"), *ThisTank);
		return;
	}
	
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Socket"));
	//= Barrel->GetSocketLocation(FName("Muzzle"));

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLocation, LaunchSpeed, false, 0.0, 0.0, ESuggestProjVelocityTraceOption::DoNotTrace);
	
	if(bHaveAimSolution){
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		
		auto Time = GetWorld()->GetRealTimeSeconds();
		auto TankName = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%f: Aim Solution Found on %s"), Time, *TankName);
	}
	else {
		auto Time = GetWorld()->GetRealTimeSeconds();
		auto TankName = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%f: No Aim Solution on %s"), Time, *TankName);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {
	//Find Barrel's current Position
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();

	//UE_LOG(LogTemp, Warning, TEXT("%s AimAsRotatotr is %s"), *GetOwner()->GetName(), *AimAsRotator.ToString());
	
	//Find the difference between current Position and hit locaiton
	FRotator DeltaRotator = AimAsRotator - BarrelRotator;
	
	Barrel->Elevate(5);//TODO Remove HardCorded number


}