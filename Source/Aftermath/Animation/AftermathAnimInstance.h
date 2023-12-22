// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AftermathAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class AFTERMATH_API UAftermathAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	UAftermathAnimInstance();
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsPlayerFalling {false};
	
};
