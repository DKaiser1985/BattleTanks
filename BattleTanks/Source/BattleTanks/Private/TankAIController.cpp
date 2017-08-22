// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ControlledTank = Cast<ATank>(GetPawn());

	MoveToActor(PlayerTank, AcceptanceRadius, true, true, false);

	if (PlayerTank) {
		AimTowardsPlayer();
		ControlledTank->Fire();
	}

}
void ATankAIController::AimTowardsPlayer() {
	
	ControlledTank->AimAt(PlayerTank->GetActorLocation());
		
}