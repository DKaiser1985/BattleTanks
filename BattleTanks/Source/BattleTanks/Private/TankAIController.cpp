// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankAIController.h"

ATank *ATankAIController::GetControlledTank() const{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("AI Tank Not controlled"));
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("AI Tank is %s"), *ControlledTank->GetName());

}
