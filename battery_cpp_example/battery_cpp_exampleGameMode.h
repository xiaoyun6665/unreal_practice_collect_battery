// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Core.h"
#include "battery_cpp_exampleGameMode.generated.h"

UENUM(BlueprintType)
enum class EBatteryPlayState:uint8 {
	EPlaying ,
	EGameOver,
	EWon,
	EUnKnow
};

UCLASS(minimalapi)
class Abattery_cpp_exampleGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	Abattery_cpp_exampleGameMode();

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category="Power")
	float GetPowerToWin() const;

	UFUNCTION(BlueprintPure, Category="Power")
	EBatteryPlayState GetCurrentState() const;

	void SetCurrentState(EBatteryPlayState NewBatteryPlayState);
private:
	EBatteryPlayState CurrentState;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power")
	float DecayRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power")
	float PowerToWin;

	// The widget class to use for our HUD screen
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power")
	TSubclassOf<UUserWidget> HUDWidgetClass;


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power")
	UUserWidget * CurrentWidget;
};



