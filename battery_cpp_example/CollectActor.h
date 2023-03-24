// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectActor.generated.h"

UCLASS()
class BATTERY_CPP_EXAMPLE_API ACollectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectActor();
private:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="PICK UP", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* PickupMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool bIsActive;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE
		UStaticMeshComponent* GetMesh() const { return PickupMesh; };

	UFUNCTION(BlueprintPure,Category="PICK UP")
	FORCEINLINE
		bool IsActive() const { return bIsActive; };

	UFUNCTION(BlueprintCallable, Category = "PICK UP")
		void SetActive(bool NewActive) { bIsActive = NewActive; };

	UFUNCTION(BlueprintNativeEvent)
	void WasCollected();

	virtual void WasCollected_Implementation();
};
