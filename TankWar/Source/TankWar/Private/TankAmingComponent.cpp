// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAmingComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"

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
}


// Called every frame
void UTankAmingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTankAmingComponent::AimAt(FVector hitLocation, float launchSpeed)
{
	if (!this->barrel) { return; }
	FVector launchVelocity(0);
	FVector startLoc = this->barrel->GetSocketLocation(FName("Projectile"));
	float time = GetWorld()->GetTimeSeconds();

	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		launchVelocity,
		startLoc,
		hitLocation,
		launchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	))
	{
		auto aimDirection = launchVelocity.GetSafeNormal();
		MoveBarrelTowards(aimDirection);
		UE_LOG(LogTemp, Warning, TEXT("%f: %s aimming at %s from %s"), time, *GetOwner()->GetName(), *aimDirection.ToString(), *this->barrel->GetComponentLocation().ToString());
	}
	else {
		
		UE_LOG(LogTemp, Warning, TEXT("%f: Not aim solution found"), time);
	}
}

void UTankAmingComponent::SetBarrelReference(UTankBarrel * barrel)
{
	this->barrel = barrel;
}

void UTankAmingComponent::MoveBarrelTowards(FVector aimDirection)
{
	FRotator barrelRotator = this->barrel->GetForwardVector().Rotation();
	FRotator aimRotator = aimDirection.Rotation();
	FRotator deltaRotator = aimRotator - barrelRotator;
	//UE_LOG(LogTemp, Warning, TEXT("Barrel Rotator: %s"), *aimRotator.ToString());
	this->barrel->Elevate(2.0f);
}
