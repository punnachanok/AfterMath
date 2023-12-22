// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AftermathPlayerController.generated.h"

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
	void Move(const FInputActionValue& InputActionValue);
	void JumpFunc(const FInputActionValue& InputActionValue);
	
	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	TObjectPtr<UInputMappingContext> AftermathMappingContext;
};
