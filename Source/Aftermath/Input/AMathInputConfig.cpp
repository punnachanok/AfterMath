// Fill out your copyright notice in the Description page of Project Settings.


#include "../Input/AMathInputConfig.h"

const UInputAction* UAMathInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag,
	bool bLogNotFound) const
{
	for(const FAmathInputAction& Action: AbilityInputActions)
	{
		if(Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}

		if(bLogNotFound)
		{
			UE_LOG(LogTemp, Error, TEXT("Can't find AbilityInputAction for InputTag [%s], on InputConfig [%s]"), *InputTag.ToString(), *GetNameSafe(this));
		}
	}

	return nullptr;
}
