// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SubmarineBattery.generated.h"


class ASubmarineBatterySlot;

UCLASS()
class SOUSMALIN_API ASubmarineBattery : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASubmarineBattery();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<ASubmarineBatterySlot> CurrentSlot;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	USceneComponent* RootSceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

public:
	UFUNCTION(BlueprintCallable)
	void ChargeBattery(float Value);

	UFUNCTION(BlueprintCallable)
	void DischargeBattery(float Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BatteryPower;

	float MaxBatteryPower;
};
