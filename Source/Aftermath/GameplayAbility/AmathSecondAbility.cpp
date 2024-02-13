// Fill out your copyright notice in the Description page of Project Settings.


#include "AmathSecondAbility.h"
#include "Aftermath/Actor/SecondMissile.h"
#include "Aftermath/Character/MainCharacter.h"

void UAmathSecondAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                          const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                          const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	// Here APlayerController or ACharacter refer to your own player controller or character classes
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	ACharacter* PlayerActor = PC ? Cast<ACharacter>(PC->GetPawn()) : nullptr;
	
	// get player location
	FVector PlayerLocation = PlayerActor->GetActorLocation();
	// get player rotation
	FRotator PlayerRotation = PlayerActor->GetActorRotation();
	
	FVector SpawnLocation = PlayerLocation;
	FRotator SpawnRotation = PlayerRotation;

	AActor* SpawnMissile = GetWorld()->SpawnActor<AActor>(Missile, SpawnLocation, SpawnRotation);
}
