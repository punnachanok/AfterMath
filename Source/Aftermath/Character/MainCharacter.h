// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AftermathCharacterBase.h"
#include "MainCharacter.generated.h"


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

	UPROPERTY()
	UCharacterMovementComponent* CharacterMovementComponent;
protected:
	UPROPERTY(EditAnywhere, Category = "Camera")
	USpringArmComponent* SpringArm = nullptr;

	UPROPERTY(EditAnywhere, Category = "Camera")
	UCameraComponent* Camera = nullptr;

	

	UPROPERTY()
	UAnimInstance* AnimInstance {nullptr};

	UPROPERTY()
	UAftermathAnimInstance* AftermathAnimInstance;

	UPROPERTY()
	AAftermathPlayerState* AftermathPlayerState;

	// UPROPERTY()
	// UAftermathAttributeSet* AftermathAttributeSet;
};
