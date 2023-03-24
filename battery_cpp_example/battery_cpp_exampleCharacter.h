// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Components/SphereComponent.h"
#include "battery_cpp_exampleCharacter.generated.h"


UCLASS(config=Game)
class Abattery_cpp_exampleCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Collect Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* CollectAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Power, meta = (AllowPrivateAccess = "true"))
	USphereComponent* CollectionSphere;

public:
	Abattery_cpp_exampleCharacter();

	// 获取初始能量值
	UFUNCTION(BlueprintPure, Category="Power")
	float GetInitialPower();

	// 获取当前能量值
	UFUNCTION(BlueprintPure, Category = "Power")
		float GetCurrentPower();

	// 更新设置能量值
	UFUNCTION(BlueprintCallable, Category = "Power")
		void UpdatePower(float PowerChange);
protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
			

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

	UFUNCTION(BlueprintCallable,Category="Pickups")
	void CollectPickups();

	// 角色的初始能量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Power")
	float InitialPower;

	// 速度因子
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power")
	float SpeedFactor;

	// 基础速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power")
	float BaseSpeed;

	UFUNCTION(BlueprintImplementableEvent, Category = "Power")
	void PowerChangeEffect();
private:
	UPROPERTY(VisibleAnywhere, Category = "Power")
	float CharacterPower;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	/** Returns USphereComponent subobject **/
	FORCEINLINE class USphereComponent* GetCollectionSphere() const { return CollectionSphere; }

};

