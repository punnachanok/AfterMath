// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AftermathCharacterBase.h"
#include "MainCharacter.generated.h"

class UMathProblems;
class UWidgetComponent;
class UAftermathAttributeSet;
class AAftermathPlayerState;
/**
 * 
 */
class UCameraComponent;
class USpringArmComponent;
class UCharacterMovementComponent;
class UAftermathAnimInstance;
UCLASS()
class AFTERMATH_API AMainCharacter : public AAftermathCharacterBase
{
	GENERATED_BODY()

public:
	AMainCharacter();
	
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;
	virtual void OnRep_PlayerState() override;
	virtual void PossessedBy(AController* NewController) override;
	void GenerateRandomEquation();

	int Ans {0};

	UPROPERTY()
	UCharacterMovementComponent* CharacterMovementComponent;
protected:
	UPROPERTY(EditAnywhere, Category = "Camera")
	USpringArmComponent* SpringArm = nullptr;

	UPROPERTY(EditAnywhere, Category = "Camera")
	UCameraComponent* Camera = nullptr;

	UPROPERTY(EditAnywhere, Category = "MathQuestion")
	UWidgetComponent* MathQuestion = nullptr;

	UPROPERTY()
	UAnimInstance* AnimInstance {nullptr};

	UPROPERTY()
	UAftermathAnimInstance* AftermathAnimInstance;

	UPROPERTY()
	AAftermathPlayerState* AftermathPlayerState;

	TObjectPtr<UMathProblems> MathProblemWidget;
	// UPROPERTY()
	// UAftermathAttributeSet* AftermathAttributeSet;
};
