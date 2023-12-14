// Fill out your copyright notice in the Description page of Project Settings.


#include "ElectricitySubsystem.h"
#include "SousMalinSettings.h"
#include "SubmarineBattery.h"
#include "SubmarineBatterySlot.h"
#include "Kismet/KismetStringLibrary.h"


DEFINE_LOG_CATEGORY(UElectricityLog);


TStatId UElectricitySubsystem::GetStatId() const
{
	return TStatId();
}

void UElectricitySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UE_LOG(UElectricityLog, Log, TEXT("Initialize"));
	const USousMalinSettings* Settings = GetDefault<USousMalinSettings>();

	PowerConsumption = Settings->PowerConsumption;
	MaxPower = Settings->MaxElectricityPower;
	bAreLightsOn = Settings->bLightStartsOn;
}

void UElectricitySubsystem::Deinitialize()
{
	Super::Deinitialize();

}

void UElectricitySubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TryUsePower(PowerConsumption * DeltaTime);
}

bool UElectricitySubsystem::TryUsePower(float Value)
{
	if (bIsShutdown)
	{
		return false;
	}

	if(CurrentPower <= 0 && !bIsShutdown)
	{
		ShutDown();
		return false;
	}

	CurrentPower = FMath::Clamp(CurrentPower - Value , 0.0f, MaxPower);
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Emerald, FString::Printf(TEXT("%f"), CurrentPower));
	if(BatterySlot->PluggedBattery)
	{
		BatterySlot->PluggedBattery->DischargeBattery(Value);
	} else
	{
		ShutDown();
		return false;
	}
	
	OnPowerChanged.Broadcast(CurrentPower / MaxPower);

	return true;
}

void UElectricitySubsystem::ChangeBattery(float BatteryCharge)
{
	CurrentPower = BatteryCharge;
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Cyan, FString::Printf(TEXT("%f"), CurrentPower));
	OnPowerChanged.Broadcast(CurrentPower / MaxPower);
}

void UElectricitySubsystem::ShutDown()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Cyan, FString(TEXT("Electricity Shutdown")));
	bIsShutdown = true;
	OnShutDown.Broadcast();
}

void UElectricitySubsystem::Dysfunction()
{
	UE_LOG(UElectricityLog, Warning, TEXT("Dysfunctionning"));
	OnDysfunction.Broadcast();
}

void UElectricitySubsystem::Repair()
{
	bIsShutdown = false;
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Cyan, FString(TEXT("Electricity Repaired")));
	OnRepaired.Broadcast();
}

void UElectricitySubsystem::SwitchLights()
{
	UE_LOG(UElectricityLog, Warning, TEXT("Lights switched"));
	bAreLightsOn = !bAreLightsOn;
	OnLightSwitched.Broadcast(bAreLightsOn);
}

void UElectricitySubsystem::SetBatterySlot(ASubmarineBatterySlot* BatterySlotRef)
{
	UE_LOG(UElectricityLog, Warning, TEXT("Battery slot set !"));
	BatterySlot = BatterySlotRef;
}

