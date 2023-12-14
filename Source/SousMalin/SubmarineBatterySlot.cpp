// Fill out your copyright notice in the Description page of Project Settings.


#include "SubmarineBatterySlot.h"
#include "SubmarineBattery.h"
#include "Components/BoxComponent.h"

// Sets default values
ASubmarineBatterySlot::ASubmarineBatterySlot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SceneRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	RootComponent = SceneRootComponent;

	BatterySlotMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BatterySlotMesh"));
	BatterySlotMesh->SetupAttachment(RootComponent);

	BatterySlotSpot = CreateDefaultSubobject<USceneComponent>(TEXT("BatterySlotSpot"));
	BatterySlotSpot->SetupAttachment(RootComponent);

	OverlapBox = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapBox"));
	OverlapBox->SetupAttachment(RootComponent);
}

void ASubmarineBatterySlot::SlotBattery(ASubmarineBattery* Battery)
{
	PluggedBattery = Battery;
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Cyan, FString(TEXT("Slotted Battery")));
	OnSlottedBattery.Broadcast(PluggedBattery);
}

void ASubmarineBatterySlot::UnSlotBattery()
{
	PluggedBattery = nullptr;
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Cyan, FString(TEXT("Slotted Battery")));
	OnSlottedBattery.Broadcast(0);
}

// Called when the game starts or when spawned
void ASubmarineBatterySlot::BeginPlay()
{
	Super::BeginPlay();

}

