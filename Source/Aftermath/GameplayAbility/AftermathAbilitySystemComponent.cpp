// Fill out your copyright notice in the Description page of Project Settings.


#include "../GameplayAbility/AftermathAbilitySystemComponent.h"

#include "AMathGameplayAbility.h"
#include "Aftermath/Misc/AmathGameplayTags.h"

void UAftermathAbilitySystemComponent::AddCharacterAbilities(
	const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
	for(const TSubclassOf<UGameplayAbility> AbilityClass : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
		
		if(const UAMathGameplayAbility* AMathAbility = Cast<UAMathGameplayAbility>(AbilitySpec.Ability))
		{
			AbilitySpec.DynamicAbilityTags.AddTag(AMathAbility->StartupInputTag);
			GiveAbility(AbilitySpec);
		}
	}
	AbilityActorInfoSet();
}

void UAftermathAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAftermathAbilitySystemComponent::EffectApplied);

	const FAmathGameplayTags& GameplayTags = FAmathGameplayTags::Get();
	//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Orange, FString::Printf(TEXT("Tag: %s"), *GameplayTags.AttributeSet_Secondary_Armour.ToString()));
	//GEngine->AddOnScreenDebugMessage(0, 10.f, FColor::Orange, FString::Printf(TEXT("Tag: %s"), *GameplayTags.AttributeSet_Vital_Health.ToString()));
	//GEngine->AddOnScreenDebugMessage(1, 10.f, FColor::Orange, FString::Printf(TEXT("Tag: %s"), *GameplayTags.AttributeSet_Vital_MaxHealth.ToString()));
	//GEngine->AddOnScreenDebugMessage(2, 10.f, FColor::Orange, FString::Printf(TEXT("Tag: %s"), *GameplayTags.AttributeSet_Vital_Mana.ToString()));
	//GEngine->AddOnScreenDebugMessage(3, 10.f, FColor::Orange, FString::Printf(TEXT("Tag: %s"), *GameplayTags.AttributeSet_Vital_MaxMana.ToString()));
	//GEngine->AddOnScreenDebugMessage(4, 10.f, FColor::Orange, FString::Printf(TEXT("Tag: %s"), *GameplayTags.AttributeSet_Vital_Stamina.ToString()));
	//GEngine->AddOnScreenDebugMessage(5, 10.f, FColor::Orange, FString::Printf(TEXT("Tag: %s"), *GameplayTags.AttributeSet_Vital_MaxStamina.ToString()));
}

void UAftermathAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* Source,
	const FGameplayEffectSpec& SpecApplied, FActiveGameplayEffectHandle ActiveHandle)
{
	FGameplayTagContainer TagContainer;
	SpecApplied.GetAllAssetTags(TagContainer);
	
	
}

void UAftermathAbilitySystemComponent::AbilityInputTagHeld(const FGameplayTag& InputTag)
{
	if(!InputTag.IsValid())
	{
		return;
	}

	for(FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if(AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
		{
			AbilitySpecInputPressed(AbilitySpec);
			if(!AbilitySpec.IsActive())
			{
				TryActivateAbility(AbilitySpec.Handle);
			}
		}
	}
}

void UAftermathAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
	if(!InputTag.IsValid())
	{
		return;
	}

	for(FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if(AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
		{
			AbilitySpecInputReleased(AbilitySpec);
		}
	}
}
