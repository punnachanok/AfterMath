// Fill out your copyright notice in the Description page of Project Settings.


#include "../PlayerState/AftermathPlayerState.h"

#include "AbilitySystemComponent.h"
#include "Aftermath/GameplayAbility/AftermathAbilitySystemComponent.h"
#include "Aftermath/GameplayAbility/AftermathAttributeSet.h"

AAftermathPlayerState::AAftermathPlayerState()
{
	NetUpdateFrequency = 100;

	AbilitySystemComponent = CreateDefaultSubobject<UAftermathAbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UAftermathAttributeSet>("Attribute Set");     
}

UAbilitySystemComponent* AAftermathPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AAftermathPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}
