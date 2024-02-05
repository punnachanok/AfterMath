// Fill out your copyright notice in the Description page of Project Settings.


#include "../UI/AmathHUD.h"

#include "AmathWidgetController.h"
#include "OverlayWidgetController.h"
#include "UserWidgetBase.h"
#include "Aftermath/GameplayAbility/AftermathAttributeSet.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "../UI/OverlayWidgetController.h"
#include "Aftermath/Character/EnemyCharacter.h"

void AAmathHUD::SetOverlayWidget()
{
}

void AAmathHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class uninitialized, please fill out BP_AmathHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class uninitialized, please fill out BP_AmathHUD"));
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UUserWidgetBase>(Widget);

	AmathWidgetControllerPtr = NewObject<UOverlayWidgetController>();
	AmathWidgetControllerPtr->SetWidgetControllerParams(PC, PS, ASC, AS);
	
	
	
	OverlayWidget->SetWidgetController(AmathWidgetControllerPtr);
	AmathWidgetControllerPtr->BindCallbacksToDependencies();
	
	
	OverlayWidget->AddToViewport();

	
}

