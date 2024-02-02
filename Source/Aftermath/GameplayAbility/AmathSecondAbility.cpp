// Fill out your copyright notice in the Description page of Project Settings.


#include "AmathSecondAbility.h"

#include "Aftermath/Actor/SecondMissile.h"

void UAmathSecondAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                          const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                          const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	FVector SpawnLocation = FVector(0.f, 0.f, 0.f);
	FRotator SpawnRotation = FRotator(0.f, 0.f, 0.f);

	ASecondMissile* SpawnMissile = GetWorld()->SpawnActor<ASecondMissile>(Missile, SpawnLocation, SpawnRotation);
}