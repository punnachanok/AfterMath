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

	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::MakeRandomColor(), TEXT("RMB Ability Activated C++"));

	// Here APlayerController or ACharacter refer to your own player controller or character classes
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	ACharacter* PlayerActor = PC ? Cast<ACharacter>(PC->GetPawn()) : nullptr;
	
	// get player location
	FVector PlayerLocation = PlayerActor->GetActorLocation();
	// get player rotation
	FRotator PlayerRotation = PlayerActor->GetActorRotation();
	
	FVector SpawnLocation = PlayerLocation;
	FRotator SpawnRotation = PlayerRotation;
	bool HasAuth = HasAuthority(&ActivationInfo);
	
	AActor* SpawnedProjectile = GetWorld()->SpawnActor<AAmathProjectile>(ProjectileMissile, SpawnLocation, SpawnRotation);
}
