// Copyright Epic Games, Inc. All Rights Reserved.

#include "battery_cpp_exampleGameMode.h"
#include "battery_cpp_exampleCharacter.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "UMG.h"
#include "kismet/GameplayStatics.h"

Abattery_cpp_exampleGameMode::Abattery_cpp_exampleGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	DecayRate = 0.01f;


}

void Abattery_cpp_exampleGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Abattery_cpp_exampleCharacter *MyCharacter = Cast<Abattery_cpp_exampleCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	if(MyCharacter)
	{
		if(MyCharacter->GetCurrentPower() > PowerToWin)
		{
			SetCurrentState(EBatteryPlayState::EWon);
		}
		else if(MyCharacter->GetCurrentPower() > 0)
		{
			MyCharacter->UpdatePower(-DeltaTime * DecayRate * (MyCharacter->GetInitialPower()));
		} else
		{
			SetCurrentState(EBatteryPlayState::EGameOver);
		}
	}
}

void Abattery_cpp_exampleGameMode::BeginPlay()
{
	Super::BeginPlay();
	Abattery_cpp_exampleCharacter *MyCharacter = Cast<Abattery_cpp_exampleCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	if(MyCharacter)
	{
		PowerToWin = (MyCharacter->GetInitialPower()) * 1.25f;
	}

	if(HUDWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
		if(CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}

	SetCurrentState(EBatteryPlayState::EPlaying);
}

float Abattery_cpp_exampleGameMode::GetPowerToWin() const
{
	return PowerToWin;
}

EBatteryPlayState Abattery_cpp_exampleGameMode::GetCurrentState() const
{
	return CurrentState;
}

void Abattery_cpp_exampleGameMode::SetCurrentState(EBatteryPlayState NewBatteryPlayState)
{
	CurrentState = NewBatteryPlayState;
}
