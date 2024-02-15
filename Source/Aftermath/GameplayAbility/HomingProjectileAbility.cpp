// Fill out your copyright notice in the Description page of Project Settings.


#include "HomingProjectileAbility.h"

#include "AITypes.h"
#include "Aftermath/Actor/AmathHomingProjectile.h"
#include "Aftermath/Character/EnemyCharacter.h"
#include "Aftermath/Character/MainCharacter.h"
#include "GameFramework/Character.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

void UHomingProjectileAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                               const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                               const FGameplayEventData* TriggerEventData)
{

	// Here APlayerController or ACharacter refer to your own player controller or character classes
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	ACharacter* PlayerActor = PC ? Cast<ACharacter>(PC->GetPawn()) : nullptr;
	
	if(Cast<AMainCharacter>(PlayerActor)->IsDead)
	{
		return;
	}
	
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	
	// get player location
	FVector PlayerLocation = PlayerActor->GetActorLocation();
	// get player rotation
	FRotator PlayerRotation = PlayerActor->GetActorRotation();
	
	FVector SpawnLocation = PlayerLocation;
	FRotator SpawnRotation = PlayerRotation;
	bool HasAuth = HasAuthority(&ActivationInfo);

	
	
	AActor* SpawnedProjectile = GetWorld()->SpawnActor<AAmathHomingProjectile>(HomingProjectileMissile, SpawnLocation, SpawnRotation);
	AAmathHomingProjectile* HomingProjectile = Cast<AAmathHomingProjectile>(SpawnedProjectile);
	
	TArray<AActor*> ActorsWithTag;
	UGameplayStatics::GetAllActorsWithTag(this, FName("Enemy"), ActorsWithTag);
	float LowestDistance = 10000;
	AActor* ClosestActor = nullptr;

	for(AActor* Actor : ActorsWithTag)
	{
		if(Cast<AEnemyCharacter>(Actor)->IsDead == false)
		{
			float DistanceToTarget = Actor->GetDistanceTo(HomingProjectile);
			if(LowestDistance > DistanceToTarget)
			{
				LowestDistance = DistanceToTarget;
				ClosestActor = Actor;
			}
		}
		
		//GEngine->AddOnScreenDebugMessage(2, .5f, FColor::Orange, *Actor->GetName());
	}
	if(ClosestActor && LowestDistance < 2000)
	{
		HomingProjectile->ProjectileMovementComponent->bIsHomingProjectile = true;
		HomingProjectile->ProjectileMovementComponent->HomingAccelerationMagnitude = 2000;
		HomingProjectile->ProjectileMovementComponent->HomingTargetComponent = ClosestActor->GetRootComponent();
	}
}
