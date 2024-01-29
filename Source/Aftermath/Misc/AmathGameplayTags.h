// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * AMathGameplayTags
 *
 * Singleton containing native Gameplay Tags
 */

struct FAmathGameplayTags
{
public:
static const FAmathGameplayTags& Get() { return GameplayTags; }
static void InitializeNativeGameplayTags();
 FGameplayTag AttributeSet_Secondary_Armour;
 
 FGameplayTag AttributeSet_Vital_Health;
 FGameplayTag AttributeSet_Vital_MaxHealth;
 FGameplayTag AttributeSet_Vital_Mana;
 FGameplayTag AttributeSet_Vital_MaxMana;
 FGameplayTag AttributeSet_Vital_Stamina;
 FGameplayTag AttributeSet_Vital_MaxStamina;

 FGameplayTag InputTag_LMB;
 FGameplayTag InputTag_RMB;
 FGameplayTag InputTag_1;
 FGameplayTag InputTag_2;
 FGameplayTag InputTag_3;
 FGameplayTag InputTag_4;

private:
 static FAmathGameplayTags GameplayTags;
};
