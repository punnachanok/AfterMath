// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AMathGameplayAbility.h"
#include "HomingProjectileAbility.generated.h"

class AAmathHomingProjectile;
/**
 * 
 */
UCLASS()
class AFTERMATH_API UHomingProjectileAbility : public UAMathGameplayAbility
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AAmathHomingProjectile> HomingProjectileMissile;
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
};
