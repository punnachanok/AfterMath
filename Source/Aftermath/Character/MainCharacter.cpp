// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../Animation/AftermathAnimInstance.h"
#include "Aftermath/PlayerState/AftermathPlayerState.h"
#include "GameFramework/Character.h"
#include "Animation/AnimInstance.h"
#include "../GameplayAbility/AftermathAttributeSet.h"
#include "Aftermath/UI/AmathHUD.h"
#include "Aftermath/UI/MathProblems.h"
#include "Components/CapsuleComponent.h"
#include "Components/EditableTextBox.h"
#include "Components/WidgetComponent.h"


AMainCharacter::AMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent); // Attach to root component of the actor/character.
	SpringArm->TargetArmLength = 800.0f; // Length of the spring arm.
	SpringArm->SetRelativeRotation(FRotator(-60, 0, 0)); // Have the arm rotate as the control rotates.

	// Also in your Actor or Character Constructor
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName); // Attach camera to end of spring arm.
	Camera->bUsePawnControlRotation = false; // Let the arm control the camera rotation.

	MathQuestion = CreateDefaultSubobject<UWidgetComponent>("MathQuestion");
	MathQuestion->SetupAttachment(RootComponent);
	
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritPitch = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	
	Tags.Add(FName("Player"));
}

void AMainCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	
	FVector VectorVelocity = CharacterMovementComponent->Velocity;
	AftermathAnimInstance->Speed = VectorVelocity.Size2D();
	
	AftermathAnimInstance->IsPlayerFalling = CharacterMovementComponent->IsFalling();
	// float TempHealth = AftermathAttributeSet->HealthFloat;
	//UE_LOG(LogTemp, Warning, TEXT("PlayerHealth: %f"), TempHealth);
	//GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Black, TEXT("%f"), TempHealth);
	//UE_LOG(LogTemp, Warning, TEXT("speed: %f"), AftermathAnimInstance->Speed);
}
	




void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	CharacterMovementComponent = GetCharacterMovement(); // TODO: CharacterMovementComponent = nullptr
	check(CharacterMovementComponent);
	
	CharacterMovementComponent->bOrientRotationToMovement = true;
	CharacterMovementComponent->RotationRate = FRotator(0, 400, 0);
	check(CharacterMovementComponent)
	
	AnimInstance = GetMesh()->GetAnimInstance();
	AftermathAnimInstance = Cast<UAftermathAnimInstance>(AnimInstance);

	check(AftermathAnimInstance)
	// AftermathAttributeSet = Cast<UAftermathAttributeSet>(AftermathPlayerState->GetAttributeSet());
	// check(AftermathAttributeSet)
	//UE_LOG(LogTemp, Warning, TEXT("BeginPlay Started"));

	CharacterMovementComponent->MaxWalkSpeed = 1000;

	MathProblemWidget = Cast<UMathProblems>(MathQuestion->GetUserWidgetObject());

	GenerateRandomEquation();
}

//For the client
void AMainCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	AftermathPlayerState = GetPlayerState<AAftermathPlayerState>();
	//check(AftermathPlayerState)
	
	AbilitySystemComponent = AftermathPlayerState->GetAbilitySystemComponent();
	AbilitySystemComponent->InitAbilityActorInfo(AftermathPlayerState,  this);
	
	AttributeSet = AftermathPlayerState->GetAttributeSet();
	check(AttributeSet);
	
	APlayerController* PlayerController = AftermathPlayerState->GetPlayerController();
	AHUD* HUD = PlayerController->GetHUD();
	AAmathHUD* AmathHUD = Cast<AAmathHUD>(HUD);
	
	AmathHUD->InitOverlay(PlayerController, AftermathPlayerState, AbilitySystemComponent, AttributeSet);
}

//For the server
void AMainCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	AftermathPlayerState = GetPlayerState<AAftermathPlayerState>();

	AbilitySystemComponent = AftermathPlayerState->GetAbilitySystemComponent();
	AbilitySystemComponent->InitAbilityActorInfo(AftermathPlayerState,  this);
	AddCharacterAbilities();
	
	AttributeSet = AftermathPlayerState->GetAttributeSet();
	check(AttributeSet);

	APlayerController* PlayerController = AftermathPlayerState->GetPlayerController();
	AHUD* HUD = PlayerController->GetHUD();
	AAmathHUD* AmathHUD = Cast<AAmathHUD>(HUD);
	
	AmathHUD->InitOverlay(PlayerController, AftermathPlayerState, AbilitySystemComponent, AttributeSet);
}

void AMainCharacter::GenerateRandomEquation()
{
	TArray<FString> Operators {TEXT("+"), TEXT("-"), TEXT("*"), TEXT("/")};

	int32 Num1 = FMath::RandRange(1, 10);
	int32 Num2 = FMath::RandRange(1, 10);
	FString Op = Operators[FMath::RandRange(0, 3)];

	if(Op == "+") Ans = Num1 + Num2;
	else if (Op == "-") Ans = Num1 - Num2;
	else if (Op == "*") Ans = Num1 * Num2;
	else
	{
		Num1 *= Num2;
		Ans = Num1 / Num2;
	}

	FString Equation = FString::Printf(TEXT("%d %s %d"), Num1, *Op, Num2);
	
	MathProblemWidget->LeftAns->SetText(FText::AsNumber(Ans));
	MathProblemWidget->Question->SetText(FText::FromString(Equation));
	MathProblemWidget->RightAns->SetText(FText::AsNumber(Ans));
}
