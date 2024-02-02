// Fill out your copyright notice in the Description page of Project Settings.


#include "AMathProjectileAbility.h"

#include "Aftermath/Actor/AmathProjectile.h"
#include "Aftermath/Character/EnemyCharacter.h"
#include "Aftermath/Character/MainCharacter.h"
#include "Types/AttributeStorage.h"

void UAMathProjectileAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                              const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                              const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::MakeRandomColor(), TEXT("RMB Ability Activated C++"));
	
	FVector SpawnLocation = FVector(0.f, 0.f, 0.f);
	FRotator SpawnRotation = FRotator(0.f, 0.f, 0.f);
	bool HasAuth = HasAuthority(&ActivationInfo);
	AActor* SpawnedProjectile = GetWorld()->SpawnActor<AEnemyCharacter>(ProjectileMissile, SpawnLocation, SpawnRotation);
	
}
