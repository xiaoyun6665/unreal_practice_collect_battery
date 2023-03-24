// Fill out your copyright notice in the Description page of Project Settings.


#include "BatteryCollectActor.h"

ABatteryCollectActor::ABatteryCollectActor()
{
	GetMesh()->SetSimulatePhysics(true);
	// 电池基础的能量值
	BatteryPower = 150.f;
}

void ABatteryCollectActor::WasCollected_Implementation()
{
	Super::WasCollected_Implementation();
	Destroy();
}

float ABatteryCollectActor::GetPower() const
{

	return BatteryPower;
}
