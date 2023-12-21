// Fill out your copyright notice in the Description page of Project Settings.


#include "AftermathPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

using namespace std;

AAftermathPlayerController::AAftermathPlayerController()
{
	
	
}

void AAftermathPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* EnhancedInput = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	if(EnhancedInput)
	{
		EnhancedInput->AddMappingContext(AftermathMappingContext, 0);
	}
}

void AAftermathPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d MoveVector = InputActionValue.Get<FVector2d>();
	const FVector UpDirection = FVector(1, 0, 0);
	const FVector RightDirection = FVector(0, 1, 0);
	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(UpDirection, MoveVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, MoveVector.X);
	}
	
	
}

void AAftermathPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAftermathPlayerController::Move);
}


