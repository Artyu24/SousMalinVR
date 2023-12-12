// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ElectricitySubsystem.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(UElectricityLog, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPowerEvent, float, EletricityValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLightEvent, bool, Callback);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FElectricityEvent);

class ASubmarineBatterySlot;


UCLASS()
class SOUSMALIN_API UElectricitySubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:
	TStatId GetStatId() const override;

	void Initialize(FSubsystemCollectionBase& Collection) override;

	void Deinitialize() override;

	void Tick(float DeltaTime) override;

	UFUNCTION()
	bool TryUsePower(float Value);

	UFUNCTION()
	void ChangeBattery(float BatteryCharge);

	UFUNCTION()
	void ShutDown();

	UFUNCTION()
	void Dysfunction();

	UFUNCTION()
	void Repair();

	UPROPERTY(BlueprintAssignable)
	FPowerEvent OnPowerChanged;

	UPROPERTY(BlueprintAssignable)
	FLightEvent OnLightSwitched;

	UPROPERTY(BlueprintAssignable)
	FElectricityEvent OnBatteryChanged;

	UPROPERTY(BlueprintAssignable)
	FElectricityEvent OnShutDown;

	UPROPERTY(BlueprintAssignable)
	FElectricityEvent OnDysfunction;

	UPROPERTY(BlueprintAssignable)
	FElectricityEvent OnRepaired;

	UPROPERTY(BlueprintAssignable)
	FElectricityEvent OnPowerLow;

	UPROPERTY()
	ASubmarineBatterySlot* BatterySlot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float CurrentPower;

private:
	bool bAreLightsOn;

	bool bIsShutdown;

	bool bIsPowerLow;

	float MaxPower;

	float PowerConsumption;

	float BatteryLowCeiling;
};
