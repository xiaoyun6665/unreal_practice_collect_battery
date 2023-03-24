// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnVolume.h"

#include "CollectActor.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WhereToSpawn;

	SpawnDelayRangeLow = 1.0f;
	SpawnDelayRangeHigh = 4.5f;

}

FVector ASpawnVolume::GetRadomPointInValue()
{
	FVector SpawnOrigin = WhereToSpawn->Bounds.Origin;
	FVector SpawnExtent = WhereToSpawn->Bounds.BoxExtent;
	return UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnExtent);
}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	SpawnDelay = FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false, -1.f);

}

void ASpawnVolume::SpawnPickup()
{
	if(WhatToSpawn!=NULL)
	{
		UWorld* const World = GetWorld();
		if(World)
		{
			FActorSpawnParameters SpawnParameters;
			SpawnParameters.Owner = this;
			SpawnParameters.Instigator = GetInstigator();

			FVector SpawnLocation = GetRadomPointInValue();

			FRotator SpawnRotation;
			SpawnRotation.Yaw = FMath::FRand() * 360.0f;
			SpawnRotation.Pitch = FMath::FRand() * 360.0f;
			SpawnRotation.Roll = FMath::FRand() * 360.0f;

			ACollectActor* const SpawnedPickup = World->SpawnActor<ACollectActor>(WhatToSpawn, SpawnLocation, SpawnRotation,SpawnParameters);
			SpawnDelay = FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
			GetWorldTimerManager().SetTimer(SpawnTimer, this, & ASpawnVolume::SpawnPickup, SpawnDelay, false, -1.f);
		}
	}
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

