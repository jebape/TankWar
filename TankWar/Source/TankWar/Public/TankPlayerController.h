// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKWAR_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	ATank* GetControlledTank() const;
	
private:
	UPROPERTY(EditAnywhere)
	float crossHairXLoc = 0.5;
	UPROPERTY(EditAnywhere)
	float crossHairYLoc = 0.33333;

	void AimTowardsCrooshair();
	bool GetSightRayHitLocation(FVector& hitLoc) const;
	bool GetLookDirection(FVector2D screenLocation, FVector worldDirection) const;

};


