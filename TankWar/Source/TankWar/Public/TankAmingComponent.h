// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAmingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKWAR_API UTankAmingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAmingComponent();
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void AimAt(FVector hitLocation, float launchSpeed);
	void SetBarrelReference(UStaticMeshComponent* barrel);

private:
	UStaticMeshComponent* barrel = nullptr;

	void MoveBarrelTowards(FVector aimDirection);
	
};
