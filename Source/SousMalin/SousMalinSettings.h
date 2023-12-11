// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "SousMalinSettings.generated.h"

UCLASS(Config=Game, DefaultConfig)
class SOUSMALIN_API USousMalinSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public :
	UPROPERTY(EditAnywhere, Config)
	float MaxElectricityPower;

	UPROPERTY(EditAnywhere, Config)
	float PowerConsumption;

	UPROPERTY(EditAnywhere, Config)
	bool bLightStartsOn;

	UPROPERTY(EditAnywhere, Config)
	bool bSubmarineStartsOn;
};
