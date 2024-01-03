// Fill out your copyright notice in the Description page of Project Settings.


#include "AftermathPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../GameplayAbility/AftermathAttributeSet.h"
#include "Aftermath/PlayerState/AftermathPlayerState.h"

using namespace std;

AAftermathPlayerController::AAftermathPlayerController()
{
	RunningSpeed = 2000.f;
	WalkingSpeed = 1000.f;
	
}

void AAftermathPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* EnhancedInput = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	AMPlayerState = GetPlayerState<AAftermathPlayerState>();
	AMAttributeSet = Cast<UAftermathAttributeSet>(AMPlayerState->GetAttributeSet());

	if(EnhancedInput)
	{
		EnhancedInput->AddMappingContext(AftermathMappingContext, 0);
	}
}

void AAftermathPlayerController::MoveRun(const FInputActionValue& InputActionValueRun)
{
	const FVector2d MoveRunVector = InputActionValueRun.Get<FVector2d>();
	const FVector UpDirectionRun = FVector(1, 0, 0);
	const FVector RightDirectionRun = FVector(0, 1, 0);
	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(UpDirectionRun, MoveRunVector.Y);
		ControlledPawn->AddMovementInput(RightDirectionRun, MoveRunVector.X);
	}
}

	void AAftermathPlayerController::MoveWalk(const FInputActionValue& InputActionValueWalk)
	{
		const FVector2d MoveVector = InputActionValueWalk.Get<FVector2d>();
		const FVector UpDirectionWalk = FVector(0.25, 0, 0);
		const FVector RightDirectionWalk = FVector(0, 0.25, 0);
		if(APawn* ControlledPawn = GetPawn<APawn>())
		{
			ControlledPawn->AddMovementInput(UpDirectionWalk, MoveVector.Y);
			ControlledPawn->AddMovementInput(RightDirectionWalk, MoveVector.X);
		}
	}

	void AAftermathPlayerController::JumpFunc(const FInputActionValue& InputActionValue)
	{
		bool IsJump = InputActionValue.Get<bool>();
		if(IsJump)
		{
			GetCharacter()->Jump();
		}
	}

void AAftermathPlayerController::ShiftRunStarted(const FInputActionValue& InputActionValueShiftRunStarted)
{
	RunCoolDown = 10;
	IsRunning = true;
	GetCharacter()->GetCharacterMovement()->MaxWalkSpeed = RunningSpeed;

	//UE_LOG(LogTemp, Warning, TEXT("MaxWalkSpeed: %f"), GetCharacter()->GetCharacterMovement()->MaxWalkSpeed)

	
	
}

void AAftermathPlayerController::ShiftRunEnded(const FInputActionValue& InputActionValueShiftRunEnded)
{
	IsRunning = false;
	
	GetCharacter()->GetCharacterMovement()->MaxWalkSpeed = WalkingSpeed;
	//UE_LOG(LogTemp, Warning, TEXT("MaxWalkSpeed: %f"), GetCharacter()->GetCharacterMovement()->MaxWalkSpeed)
	RunCoolDown = 10;
}

void AAftermathPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//UE_LOG(LogTemp, Warning, TEXT("IsRunning: %s"), IsRunning ? TEXT("1") : TEXT("0"))
	UE_LOG(LogTemp, Warning, TEXT("CoolDown: %f"), RunCoolDown);
	
	if(IsRunning)
	{
		float StaminaF = AMAttributeSet->GetStamina();
		AMAttributeSet->SetStamina(StaminaF -= 0.1);
	}

	if(!IsRunning)
	{
		RunCoolDown -= 0.1;
	}

	if(RunCoolDown <= 0)
	{
		float StaminaF = AMAttributeSet->GetStamina();
		StaminaF = FMath::Clamp(StaminaF, 0, 10);
		AMAttributeSet->SetStamina(StaminaF += 0.1);
	}
}

void AAftermathPlayerController::SetupInputComponent()
	{
		Super::SetupInputComponent();

		UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAftermathPlayerController::MoveWalk);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AAftermathPlayerController::JumpFunc);
		EnhancedInputComponent->BindAction(ShiftRunActionStarted, ETriggerEvent::Triggered, this, &AAftermathPlayerController::ShiftRunStarted);
		EnhancedInputComponent->BindAction(ShiftRunActionStarted, ETriggerEvent::Completed, this, &AAftermathPlayerController::ShiftRunEnded);
	}



