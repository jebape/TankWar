// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class TANKWAR_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float degreesPerSecond);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float maxDegreesPerSecond = 10.0f;
	UPROPERTY(EditAnywhere, Category = Setup)
		float maxElevationDegrees = 35.0f;
	UPROPERTY(EditAnywhere, Category = Setup)
		float minElevationDegrees = -10.0f;
	
};
