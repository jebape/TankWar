// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto controlledTank = GetControlledTank();
	if (!controlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("There's no controlled AI tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI controller possesing: %s"), *(controlledTank->GetName()));
	}
	
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

