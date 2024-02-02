// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AMathGameplayAbility.h"
#include "AMathProjectileAbility.generated.h"

class AEnemyCharacter;
class AAmathProjectile;
/**
 * 
 */
UCLASS()
class AFTERMATH_API UAMathProjectileAbility : public UAMathGameplayAbility
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AAmathProjectile> ProjectileMissile;
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
};
