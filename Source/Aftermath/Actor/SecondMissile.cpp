// Fill out your copyright notice in the Description page of Project Settings.


#include "SecondMissile.h"
#include "SecondMissile.h"
#include "NiagaraComponent.h"
#include "NiagaraSystem.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
ASecondMissile::ASecondMissile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Niagara = CreateDefaultSubobject<UNiagaraComponent>("Niagara");
	Scene = CreateDefaultSubobject<USceneComponent>("Scene");
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");

	SetRootComponent(Scene);
	Sphere->SetupAttachment(Scene);
	Niagara->SetupAttachment(Sphere);

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

