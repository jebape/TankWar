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
	UE_LOG(LogTemp, Warning, TEXT("Player Controller BeginPlay"));
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}
