// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

//Holds Tank Properties
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision") )
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float RelativeSpeed);
	
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 20; 
	
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxPitchDegrees = 40; 
	
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinPitchDegrees = 0; 
	
};