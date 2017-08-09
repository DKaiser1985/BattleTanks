// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	//FVector OutLaunchVelocity;
	//FVector StartLocation = Barrel->GetSocketLocation(FName("Muzzle"));

	auto OurTankName = GetOwner()->GetName();


	if (Barrel == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Barrel is NULL"));
		return;
	}
	else {
		auto BarrelLocation = Barrel->GetComponentLocation().ToString();
		UE_LOG(LogTemp, Warning, TEXT("Barrel is not Null"));
	}
	//Calculate the OutLaunchVelocity
		//auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		


	}