// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AftermathCharacterBase.h"
#include "MainCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class AFTERMATH_API AMainCharacter : public AAftermathCharacterBase
{
	GENERATED_BODY()

public:
	AMainCharacter();
protected:
	UPROPERTY(EditAnywhere, Category = "Camera")
	USpringArmComponent* SpringArm = nullptr;

	UPROPERTY(EditAnywhere, Category = "Camera")
	UCameraComponent* Camera = nullptr;
};
