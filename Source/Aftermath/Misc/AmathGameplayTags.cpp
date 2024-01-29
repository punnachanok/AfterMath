// Fill out your copyright notice in the Description page of Project Settings.


#include "../Misc/AmathGameplayTags.h"

#include "GameplayTagsManager.h"

FAmathGameplayTags FAmathGameplayTags::GameplayTags;

void FAmathGameplayTags::InitializeNativeGameplayTags()
{
	GameplayTags.AttributeSet_Secondary_Armour = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armor"), FString("Reduces damage taken, improves Block Chance"));
	GameplayTags.AttributeSet_Vital_Health = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.Health"), FString("Player's current hit point"));
	GameplayTags.AttributeSet_Vital_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.MaxHealth"), FString("Player's max hit point"));
	GameplayTags.AttributeSet_Vital_Mana = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.Mana"), FString("Player's current Mana point"));
	GameplayTags.AttributeSet_Vital_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.MaxMana"), FString("Player's max Mana point"));
	GameplayTags.AttributeSet_Vital_Stamina = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.Stamina"), FString("Player's current Stamina point"));
	GameplayTags.AttributeSet_Vital_MaxStamina = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.MaxStamina"), FString("Player's max Stamina point"));

	/*
	 * Input Tags
	 */
	
	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.LMB"), FString("Input tag for Left Mouse Button"));
	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.RMB"), FString("Input tag for Right Mouse Button"));
	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.1"), FString("Input tag for 1 key"));
	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.2"), FString("Input tag for 2 key"));
	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.3"), FString("Input tag for 3 key"));
	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.4"), FString("Input tag for 4 key"));
}
