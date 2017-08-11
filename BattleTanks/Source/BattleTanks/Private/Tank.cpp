// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//No Need to protect pointers as added at construction
	//Added Tank Aiming component as a default Subobject
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName ("Aiming Component"));

}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet) {

	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}
void ATank::SetTurretReference(UTankTurret* TurretToSet) {

	TankAimingComponent->SetTurretReference(TurretToSet);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void ATank::AimAt(FVector HitLocation) {
	//Pass down to TankAimingComponent
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}
void ATank::Fire() {
	
	//auto Time = GetWorld()->GetRealTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("Tank fired a projectile at %f seconds"), Time);

	if (!Barrel) { return; } //Protect Pointer
	
	//Spawn Projectile at the Muzzle socket of the Barrel
	FVector Muzzle = Barrel->GetSocketLocation(FName("Muzzle"));
	FRotator Rotator = Barrel->GetSocketRotation(FName("Muzzle"));;
	auto Projectile  = GetWorld()->SpawnActor <AProjectile>(ProjectileBlueprint, Muzzle, Rotator);

	//Launch The Projectile
	Projectile->LaunchProjectile(LaunchSpeed);
}


