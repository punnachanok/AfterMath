// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAttackAbility.h"

#include "Aftermath/Actor/AmathProjectile.h"
#include "GameFramework/Character.h"

void UEnemyAttackAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                          const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                          const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if(EnemyProjectile) 
	{
		FVector SpawnLocation = ActorInfo->AvatarActor->GetActorLocation();

		FRotator SpawnRotation = ActorInfo->AvatarActor->GetActorRotation();
		AAmathProjectile* Projectile = GetWorld()->SpawnActor<AAmathProjectile>(EnemyProjectile, SpawnLocation, SpawnRotation);

		if (Projectile) 
		{
			FVector LaunchDirection = ActorInfo->AvatarActor->GetActorForwardVector();
		}
	}
}
