// Fill out your copyright notice in the Description page of Project Settings.


#include "../UI/AmathWidgetController.h"

#include "Aftermath/GameplayAbility/AftermathAttributeSet.h"

// void UAmathWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
// {
// 	PlayerController = WCParams.PlayerController;
// 	PlayerState = WCParams.PlayerState;
// 	AbilitySystemComponent = WCParams.AbilitySystemComponent;
// 	AttributeSet = WCParams.AttributeSet;
// }

void UAmathWidgetController::SetWidgetControllerParams(APlayerController* PC, APlayerState* PS,
	UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	PlayerController = PC;
	PlayerState = PS;
	AbilitySystemComponent = ASC;
	AttributeSet = AS;
}

float UAmathWidgetController::GetHealthPercent(float Health, float MaxHealth)
{
	//TODO: Health / MaxHealth = Percent
	return 0;
}

void UAmathWidgetController::BindCallbacksToDependencies()
{
	// AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate();
}

void UAmathWidgetController::HealthChanged(const FOnAttributeChangeData& Data)
{
}

void UAmathWidgetController::MaxHealthChanged(FOnAttributeChangeData& MaxHealthChanged)
{
}
