// Fill out your copyright notice in the Description page of Project Settings.


#include "../PlayerState/AftermathPlayerState.h"

#include "AbilitySystemComponent.h"

AAftermathPlayerState::AAftermathPlayerState()
{
	NetUpdateFrequency = 100;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);
	
	AttributeSet = CreateDefaultSubobject<UAttributeSet>("Attribute Set");
}

UAbilitySystemComponent* AAftermathPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AAftermathPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}
