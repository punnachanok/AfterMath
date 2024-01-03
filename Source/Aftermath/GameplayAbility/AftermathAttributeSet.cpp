// Fill out your copyright notice in the Description page of Project Settings.


#include "../GameplayAbility/AftermathAttributeSet.h"

#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

UAftermathAttributeSet::UAftermathAttributeSet()
{
	InitHealth(50);
	InitMaxHealth(100);

	InitMana(25);
	InitMaxMana(50);

	InitStamina(10);
	InitMaxStamina(10);

	// HealthFloat = GetHealth();
	// MaxHealthFloat = GetMaxHealth();

	// UE_LOG(LogTemp, Warning, TEXT("Health: %f"), HealthFloat);
	// UE_LOG(LogTemp, Warning, TEXT("MaxHealth: %f"), MaxHealthFloat);
}

void UAftermathAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAftermathAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAftermathAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAftermathAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAftermathAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAftermathAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAftermathAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
}

void UAftermathAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAftermathAttributeSet, Health, OldHealth);
}

void UAftermathAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAftermathAttributeSet, MaxHealth, OldMaxHealth);
}

void UAftermathAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAftermathAttributeSet, Mana, OldMana);
}

void UAftermathAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAftermathAttributeSet, MaxMana, OldMaxMana);
}

void UAftermathAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAftermathAttributeSet, Stamina, OldStamina);
}

void UAftermathAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAftermathAttributeSet, MaxStamina, OldMaxStamina);
}
