// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	auto controlledTank = GetControlledTank();
	if (!controlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("There's no controlled tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player controller possesing: %s"), *(controlledTank->GetName()));
	}
	
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCrooshair();
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrooshair() {
	if (!GetControlledTank()) return;

	FVector hitLocation;
	if (GetSightRayHitLocation(hitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *hitLocation.ToString());
			// todo: tell controlled tank to aim at that point
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& hitLoc) const
{
	// find crosshair position
	int32 viewPortSizeX, viewPortSizeY;
	GetViewportSize(viewPortSizeX, viewPortSizeY);
	
	auto screenLocation = FVector2D(viewPortSizeX * crossHairXLoc, viewPortSizeY * crossHairYLoc);
	
	// De-project screen cursor position to world direction
	FVector lookDirection;
	if(GetLookDirection(screenLocation, lookDirection))
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *lookDirection.ToString());
	// Line trace along that direction
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D screenLocation, FVector worldDirection) const
{
	FVector worldLoc;
	return DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, worldLoc, worldDirection);
}
