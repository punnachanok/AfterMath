// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../Animation/AftermathAnimInstance.h"
#include "GameFramework/Character.h"
#include "Animation/AnimInstance.h"

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

	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritPitch = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	
}

void AMainCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	
	FVector VectorVelocity = CharacterMovementComponent->Velocity;
	AftermathAnimInstance->Speed = VectorVelocity.Size2D();
	
	AftermathAnimInstance->IsPlayerFalling = CharacterMovementComponent->IsFalling();
}
	//UE_LOG(LogTemp, Warning, TEXT("speed: %f"), AftermathAnimInstance->Speed);


void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();

	CharacterMovementComponent = GetCharacterMovement();
	
	CharacterMovementComponent->bOrientRotationToMovement = true;
	CharacterMovementComponent->RotationRate = FRotator(0, 400, 0);
	check(CharacterMovementComponent)
	
	AnimInstance = GetMesh()->GetAnimInstance();
	AftermathAnimInstance = Cast<UAftermathAnimInstance>(AnimInstance);

	check(AftermathAnimInstance)
	
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay Started"));
}
