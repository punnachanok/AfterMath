// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AmathWidgetController.h"
#include "GameFramework/HUD.h"
#include "AmathHUD.generated.h"

class AEnemyCharacter;
class UOverlayWidgetController;
class UAmathWidgetController;
class UAttributeSet;
class UAbilitySystemComponent;
class UUserWidgetBase;
class UUserWidget;

/**
 * 
 */
UCLASS()
class AFTERMATH_API AAmathHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void SetOverlayWidget();

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);
	
protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> OverlayWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAmathWidgetController> OverlayWidgetControllerClass;

	UPROPERTY()
	UOverlayWidgetController* AmathWidgetControllerPtr;

	TObjectPtr<UUserWidgetBase> OverlayWidget;
	
};
