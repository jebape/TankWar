// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "Tank.h"



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
	GetSightRayHitLocation(hitLocation);
	GetControlledTank()->AimAt(hitLocation);
	// todo: tell controlled tank to aim at that point
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& hitLoc) const
{
	// find crosshair position
	int32 viewPortSizeX, viewPortSizeY;
	GetViewportSize(viewPortSizeX, viewPortSizeY);
	
	auto screenLocation = FVector2D(viewPortSizeX * crossHairXLoc, viewPortSizeY * crossHairYLoc);
	
	// De-project screen cursor position to world direction
	if (GetLookVectorHitLocation(screenLocation, hitLoc)) {
		return true;
	}
	
	return false;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector2D screenLocation, FVector & hitLoc) const
{
	FVector LookDirection;
	FVector CameraLocation;
	if (DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, CameraLocation, LookDirection))
	{
		// Line-trace along that LookDirection, and see what we hit (up to max range)
		FHitResult HitResult;
		auto EndLocation = CameraLocation + (LookDirection * lineTraceRange);
		if (GetWorld()->LineTraceSingleByChannel(HitResult, CameraLocation, EndLocation, ECollisionChannel::ECC_Visibility))
		{
			hitLoc = HitResult.Location;
			return true;
		}
		hitLoc = FVector(0.0f);
	}
	return false;
}
