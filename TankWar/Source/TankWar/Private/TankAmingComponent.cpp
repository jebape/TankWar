// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAmingComponent.h"


// Sets default values for this component's properties
UTankAmingComponent::UTankAmingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAmingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAmingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAmingComponent::AimAt(FVector hitLocation)
{
	UE_LOG(LogTemp, Warning, TEXT("%s aimming at %s from %s"), *GetOwner()->GetName(), *hitLocation.ToString(), *this->barrel->GetComponentLocation().ToString());
}

void UTankAmingComponent::SetBarrelReference(UStaticMeshComponent * barrel)
{
	this->barrel = barrel;
}