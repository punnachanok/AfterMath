// Fill out your copyright notice in the Description page of Project Settings.


#include "SecondMissile.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
ASecondMissile::ASecondMissile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Scene = CreateDefaultSubobject<USceneComponent>("Scene");
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");

	SetRootComponent(Scene);
	Mesh->SetupAttachment(Scene);
	Sphere->SetupAttachment(Scene);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
	ProjectileMovementComponent->InitialSpeed = 200.f;
	ProjectileMovementComponent->MaxSpeed = 200.f;
	ProjectileMovementComponent->ProjectileGravityScale = 0;
}

// Called when the game starts or when spawned
void ASecondMissile::BeginPlay()
{
	Super::BeginPlay();
	
}

