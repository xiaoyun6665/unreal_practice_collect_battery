// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "CollectActor.h"

#include "SpawnVolume.generated.h"


UCLASS()
class BATTERY_CPP_EXAMPLE_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();
	FORCEINLINE
		UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; }

	UFUNCTION(BlueprintPure,Category="Spawning")
	FVector GetRadomPointInValue();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,Category="Spawning")
	TSubclassOf<ACollectActor>WhatToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		float SpawnDelayRangeLow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		float SpawnDelayRangeHigh;

	FTimerHandle SpawnTimer;
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Spawning",meta=(AllowPrivateAccess="true"))
	UBoxComponent* WhereToSpawn;
	void SpawnPickup();

	float SpawnDelay;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
