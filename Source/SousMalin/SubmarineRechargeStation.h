// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Steerable.h"
#include "SubmarineBatterySlot.h"
#include "SubmarineRechargeStation.generated.h"

/**
 * 
 */
UCLASS()
class SOUSMALIN_API ASubmarineRechargeStation : public ASubmarineBatterySlot, public ISteerable
{
	GENERATED_BODY()

public:
	void SlotBattery(ASubmarineBattery* Battery) override;

	void UnSlotBattery() override;

	UFUNCTION(BlueprintCallable)
	void SteerValue(float Value) override;
};
