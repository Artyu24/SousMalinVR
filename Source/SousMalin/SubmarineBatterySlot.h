// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SubmarineBatterySlot.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBatterySlotEvent, ASubmarineBattery* , Battery);

class ASubmarineBattery;
class UBoxComponent;

UCLASS()
class SOUSMALIN_API ASubmarineBatterySlot : public AActor
{
	GENERATED_BODY()
	
public:	
	ASubmarineBatterySlot();

	UFUNCTION(BlueprintCallable)
	virtual void SlotBattery(ASubmarineBattery* Battery);

	UFUNCTION(BlueprintCallable)
	virtual void UnSlotBattery();

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<ASubmarineBattery> PluggedBattery;

	UPROPERTY(BlueprintAssignable)
	FBatterySlotEvent OnSlottedBattery;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* SceneRootComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* BatterySlotMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* BatterySlotSpot;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UBoxComponent* OverlapBox;
	
};
