// Fill out your copyright notice in the Description page of Project Settings.


#include "SubmarineBattery.h"
#include "SousMalinSettings.h"

// Sets default values
ASubmarineBattery::ASubmarineBattery()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootSceneComponent;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void ASubmarineBattery::BeginPlay()
{
	Super::BeginPlay();

	const USousMalinSettings* Settings = GetDefault<USousMalinSettings>();
	MaxBatteryPower = Settings->MaxElectricityPower;
}

void ASubmarineBattery::ChargeBattery(float Value)
{
	BatteryPower = FMath::Clamp(BatteryPower + Value, 0, MaxBatteryPower);
}

void ASubmarineBattery::DischargeBattery(float Value)
{
	BatteryPower = FMath::Clamp(BatteryPower - Value, 0, MaxBatteryPower);
}

