// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "AMathInputConfig.generated.h"

USTRUCT(BlueprintType)
struct FAmathInputAction
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	const class UInputAction* InputAction = nullptr;

	UPROPERTY(EditAnywhere)
	FGameplayTag InputTag = FGameplayTag();
};

/**
 * \class UAMathInputConfig
 *
 * \brief This class represents a configuration for math input actions.
 *
 * UAMathInputConfig is a data asset that contains a list of FAmathInputAction, which represent math input actions.
 * It provides a method to find an ability input action for a given gameplay tag.
 */
UCLASS()
class AFTERMATH_API UAMathInputConfig : public UDataAsset
{
	GENERATED_BODY()
public:



	const UInputAction* FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound = false) const;
	
	

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FAmathInputAction> AbilityInputActions;
};
