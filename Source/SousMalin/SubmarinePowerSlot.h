// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SubmarineBatterySlot.h"
#include "SubmarinePowerSlot.generated.h"

UCLASS()
class SOUSMALIN_API ASubmarinePowerSlot : public ASubmarineBatterySlot
{
	GENERATED_BODY()

public:
	void SlotBattery(ASubmarineBattery* Battery) override;

	void UnSlotBattery() override;

protected:
	void BeginPlay() override;
};
