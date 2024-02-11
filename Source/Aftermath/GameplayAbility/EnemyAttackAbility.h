// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AMathGameplayAbility.h"
#include "EnemyAttackAbility.generated.h"

class AAmathProjectile;
/**
 * 
 */
UCLASS()
class AFTERMATH_API UEnemyAttackAbility : public UAMathGameplayAbility
{
	GENERATED_BODY()

protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	UPROPERTY(EditAnywhere, Category = "Projectiles")
	TSubclassOf<AAmathProjectile> EnemyProjectile;
};
