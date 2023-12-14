// Fill out your copyright notice in the Description page of Project Settings.


#include "SubmarinePowerSlot.h"
#include "ElectricitySubsystem.h"
#include "SubmarineBattery.h"


void ASubmarinePowerSlot::SlotBattery(ASubmarineBattery* Battery)
{
	ASubmarineBatterySlot::SlotBattery(Battery);

	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Cyan, FString(TEXT("Slotted Battery")));
	GetWorld()->GetSubsystem<UElectricitySubsystem>()->ChangeBattery(PluggedBattery->BatteryPower);
}

void ASubmarinePowerSlot::UnSlotBattery()
{
	ASubmarineBatterySlot::UnSlotBattery();

	GetWorld()->GetSubsystem<UElectricitySubsystem>()->ChangeBattery(0);
}

void ASubmarinePowerSlot::BeginPlay()
{
	ASubmarineBatterySlot::BeginPlay();

	GetWorld()->GetSubsystem<UElectricitySubsystem>()->SetBatterySlot(this);

}
