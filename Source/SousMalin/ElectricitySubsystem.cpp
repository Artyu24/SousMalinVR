// Fill out your copyright notice in the Description page of Project Settings.


#include "ElectricitySubsystem.h"
#include "SousMalinSettings.h"


DEFINE_LOG_CATEGORY(UElectricityLog);


void UElectricitySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UE_LOG(UElectricityLog, Log, TEXT("Initialize"));
	const USousMalinSettings* Settings = GetDefault<USousMalinSettings>();

	PowerConsumption = Settings->PowerConsumption;
	MaxPower = Settings->MaxElectricityPower;
	bAreLightsOn = Settings->bLightStartsOn;
	bIsShutdown = Settings->bSubmarineStartsOn;
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
	OnPowerChanged.Broadcast(CurrentPower / MaxPower);

	return true;
}

void UElectricitySubsystem::ChangeBattery(float BatteryCharge)
{
	CurrentPower = BatteryCharge;
	OnPowerChanged.Broadcast(CurrentPower / MaxPower);
}

void UElectricitySubsystem::ShutDown()
{
	bIsShutdown = true;
	OnShutDown.Broadcast();
}

void UElectricitySubsystem::Dysfunction()
{
	OnDysfunction.Broadcast();
}

void UElectricitySubsystem::Repair()
{
	bIsShutdown = false;
	OnRepaired.Broadcast();
}
