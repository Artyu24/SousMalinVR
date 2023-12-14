// Fill out your copyright notice in the Description page of Project Settings.


#include "SubmarineRechargeStation.h"

#include "SubmarineBattery.h"

void ASubmarineRechargeStation::SlotBattery(ASubmarineBattery* Battery)
{
	ASubmarineBatterySlot::SlotBattery(Battery);

}

void ASubmarineRechargeStation::UnSlotBattery()
{
	ASubmarineBatterySlot::UnSlotBattery();

}

void ASubmarineRechargeStation::SteerValue(float Value)
{
	if(!PluggedBattery)
	{
		return;
	}

	PluggedBattery->ChargeBattery(Value);
}
