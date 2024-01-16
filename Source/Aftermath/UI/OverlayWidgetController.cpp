// Fill out your copyright notice in the Description page of Project Settings.


#include "../UI/OverlayWidgetController.h"

#include "Aftermath/GameplayAbility/AftermathAttributeSet.h"

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	
	const UAftermathAttributeSet* AMathAttributeSet = CastChecked<UAftermathAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AMathAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AMathAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AMathAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AMathAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AMathAttributeSet->GetStaminaAttribute()).AddUObject(this, &UOverlayWidgetController::StaminaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AMathAttributeSet->GetMaxStaminaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxStaminaChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
	FString floatAsString = FString::Printf(TEXT("%f"), Data.NewValue);
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Emerald, floatAsString);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);

	FString floatAsString = FString::Printf(TEXT("%f"), Data.NewValue);
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Silver, floatAsString);
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Silver, "OnMaxHealthChangedCalled");
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::StaminaChanged(const FOnAttributeChangeData& Data) const
{
	OnStaminaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxStaminaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxStaminaChanged.Broadcast(Data.NewValue);
}
