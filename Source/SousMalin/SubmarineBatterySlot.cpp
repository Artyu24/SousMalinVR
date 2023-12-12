// Fill out your copyright notice in the Description page of Project Settings.


#include "SubmarineBatterySlot.h"
#include "ElectricitySubsystem.h"

// Sets default values
ASubmarineBatterySlot::ASubmarineBatterySlot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BatterySlotMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BatterySlotMesh"));
	RootComponent = BatterySlotMesh;

	BatterySlotSpot->SetupAttachment(BatterySlotMesh);
}

// Called when the game starts or when spawned
void ASubmarineBatterySlot::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetSubsystem<UElectricitySubsystem>()->BatterySlot = this;
}

// Called every frame
void ASubmarineBatterySlot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

