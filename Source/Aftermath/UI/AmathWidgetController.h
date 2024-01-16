// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AmathWidgetController.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
/**
 * 
 */

// USTRUCT(BlueprintType)
// struct FWidgetControllerParams
// {
// 	GENERATED_BODY()
//
// 	FWidgetControllerParams() {}
// 	FWidgetControllerParams(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
// 		: PlayerController(PC), PlayerState(PS), AbilitySystemComponent(ASC), AttributeSet(AS) {}
// 	
// 	UPROPERTY(EditAnywhere, BlueprintReadWrite)
// 	TObjectPtr<APlayerController> PlayerController;
//
// 	UPROPERTY(EditAnywhere, BlueprintReadWrite)
// 	TObjectPtr<APlayerState> PlayerState;
//
// 	UPROPERTY(EditAnywhere, BlueprintReadWrite)
// 	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
// 	
// 	UPROPERTY(EditAnywhere, BlueprintReadWrite)
// 	TObjectPtr<UAttributeSet> AttributeSet;
// };

UCLASS(Blueprintable, BlueprintType)
class AFTERMATH_API UAmathWidgetController : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
	TObjectPtr<UAttributeSet> AttributeSet;
	
	UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
	TObjectPtr<APlayerController> PlayerController;

	// UFUNCTION(BlueprintCallable)
	// void SetWidgetControllerParams(const FWidgetControllerParams& WCParams);
	
	void SetWidgetControllerParams(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);
	//virtual void InitGlobe();
	float GetHealthPercent(float Health, float MaxHealth);
	virtual void BindCallbacksToDependencies();

protected:
	void HealthChanged(const FOnAttributeChangeData& Data);
	void MaxHealthChanged(FOnAttributeChangeData& MaxHealthChanged);
};
