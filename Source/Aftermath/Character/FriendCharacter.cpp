// Fill out your copyright notice in the Description page of Project Settings.


#include "../Character/FriendCharacter.h"
#include "Aftermath/GameplayAbility/AftermathAttributeSet.h"
#include "Aftermath/GameplayAbility/AftermathAbilitySystemComponent.h"

AFriendCharacter::AFriendCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAftermathAbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<UAftermathAttributeSet>("Attribute Set"); // 0x000006b32dfe60c0 (Name="Attribute Set")
}

void AFriendCharacter::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this,  this);
}


