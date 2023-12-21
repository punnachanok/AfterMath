// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

AMainCharacter::AMainCharacter()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent); // Attach to root component of the actor/character.
	SpringArm->TargetArmLength = 800.0f; // Length of the spring arm.
	SpringArm->SetRelativeRotation(FRotator(-60, 0, 0)); // Have the arm rotate as the control rotates.

	// Also in your Actor or Character Constructor
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName); // Attach camera to end of spring arm.
	Camera->bUsePawnControlRotation = false; // Let the arm control the camera rotation.
}
