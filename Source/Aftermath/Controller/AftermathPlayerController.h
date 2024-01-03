// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AftermathPlayerController.generated.h"

class AAftermathPlayerState;
class UAftermathAttributeSet;
struct FInputActionValue;
/**
 * 
 */
class UInputMappingContext;
class UInputAction;

UCLASS()
class AFTERMATH_API AAftermathPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAftermathPlayerController();

protected:
	virtual void BeginPlay() override;
	
	virtual void SetupInputComponent() override;
private:
	void MoveRun(const FInputActionValue& InputActionValueRun);
	void MoveWalk(const FInputActionValue& InputActionValueWalk);
	void JumpFunc(const FInputActionValue& InputActionValueJump);
	void ShiftRunStarted(const FInputActionValue& InputActionValueShiftRunStarted);
	void ShiftRunEnded(const FInputActionValue& InputActionValueShiftRunEnded);
	
	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	TObjectPtr<UInputAction> ShiftRunActionStarted;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	TObjectPtr<UInputMappingContext> AftermathMappingContext;

	UPROPERTY()
	AAftermathPlayerState* AMPlayerState;

	UPROPERTY()
	UAftermathAttributeSet* AMAttributeSet;
	
	UPROPERTY()
	float RunCoolDown = 10;
	
	UPROPERTY()
	bool IsRunning = false;

	UFUNCTION()
	virtual void Tick(float DeltaSeconds) override;

	float RunningSpeed = 800.f;
	float WalkingSpeed = 600.f;
};
