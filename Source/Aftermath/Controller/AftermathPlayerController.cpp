// Fill out your copyright notice in the Description page of Project Settings.


#include "AftermathPlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../GameplayAbility/AftermathAttributeSet.h"
#include "Aftermath/GameplayAbility/AftermathAbilitySystemComponent.h"
#include "Aftermath/Input/AMathEnhancedInputComponent.h"
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
			if(StaticCast<int>(abs(MoveVector.X + MoveVector.Y)) % 2 == 1)
			{
				ControlledPawn->AddMovementInput(UpDirectionWalk, MoveVector.Y);
				
				ControlledPawn->AddMovementInput(RightDirectionWalk, MoveVector.X);
			}
			else if(StaticCast<int>(MoveVector.X + MoveVector.Y) % 2 == 0)
			{
				ControlledPawn->AddMovementInput(UpDirectionWalk / sqrt(2), MoveVector.Y);
				ControlledPawn->AddMovementInput(RightDirectionWalk / sqrt(2), MoveVector.X);
			}
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
	//UE_LOG(LogTemp, Warning, TEXT("CoolDown: %f"), RunCoolDown);
	float StaminaF = AMAttributeSet->GetStamina();
	
	
	if(IsRunning)
	{
		AMAttributeSet->SetStamina(StaminaF -= 10 * DeltaSeconds);
	}

	if(!IsRunning)
	{
		RunCoolDown -= 10 * DeltaSeconds;
	}

	if(RunCoolDown <= 0)
	{
		
		StaminaF = FMath::Clamp(StaminaF, 0, 50);
		AMAttributeSet->SetStamina(StaminaF += 10 * DeltaSeconds);
	}
	if(StaminaF <= 0)
	{
		GetCharacter()->GetCharacterMovement()->MaxWalkSpeed = 1000;
	}	
}

void AAftermathPlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
	//GEngine->AddOnScreenDebugMessage(1, 3.f, FColor::Silver, FString::Printf(TEXT("C++ %s"), *InputTag.ToString()));
}

void AAftermathPlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
	if(GetASC() == nullptr)
	{
		return;
	}
	GetASC()->AbilityInputTagReleased(InputTag);
}

void AAftermathPlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
	if(GetASC() == nullptr)
	{
		return;
	}
	
	GetASC()->AbilityInputTagHeld(InputTag);
}

UAftermathAbilitySystemComponent* AAftermathPlayerController::GetASC()
{
	if(AMathAbilitySystemComponent == nullptr)
	{
		AMathAbilitySystemComponent = Cast<UAftermathAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
	}

	return AMathAbilitySystemComponent;
}

void AAftermathPlayerController::SetupInputComponent()
	{
		Super::SetupInputComponent();

		UAMathEnhancedInputComponent* AMathInputComponent = Cast<UAMathEnhancedInputComponent>(InputComponent);
		AMathInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAftermathPlayerController::MoveWalk);
		AMathInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AAftermathPlayerController::JumpFunc);
		AMathInputComponent->BindAction(ShiftRunActionStarted, ETriggerEvent::Triggered, this, &AAftermathPlayerController::ShiftRunStarted);
		AMathInputComponent->BindAction(ShiftRunActionStarted, ETriggerEvent::Completed, this, &AAftermathPlayerController::ShiftRunEnded);

		AMathInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
	}



