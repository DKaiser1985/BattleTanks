// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankAIController.h"

ATank *ATankAIController::GetControlledTank() const{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	

	if (!PlayerTank) {
		UE_LOG(LogTemp, Error, TEXT("AI can not find Player Tank"));
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("AI can See Player Tank: %s"), *PlayerTank->GetName());

}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//TODO MoveTowardsPlayer();
	if (GetPlayerTank()) {
		AimTowardsPlayer();
	}
	//FireIfReady();

}
void ATankAIController::AimTowardsPlayer() {
	
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		
}
ATank* ATankAIController::GetPlayerTank() const {

	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) {
		return nullptr;
	}
	
	else
		return Cast<ATank>(PlayerPawn);
}
