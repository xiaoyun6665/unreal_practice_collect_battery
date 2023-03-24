// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollectActor.h"
#include "BatteryCollectActor.generated.h"

/**
 * 
 */
UCLASS()
class BATTERY_CPP_EXAMPLE_API ABatteryCollectActor : public ACollectActor
{
	GENERATED_BODY()

public:
	ABatteryCollectActor();

	void WasCollected_Implementation() override;

	// 获取能量
	float GetPower() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Power")
	float BatteryPower;
};
