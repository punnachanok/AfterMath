// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AMathGameplayAbility.h"
#include "AmathSecondAbility.generated.h"

class ASecondMissile;
/**
 * 
 */
UCLASS()
class AFTERMATH_API UAmathSecondAbility : public UAMathGameplayAbility
{
	GENERATED_BODY()
public:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> Missile;
	
};
