// Fill out your copyright notice in the Description page of Project Settings.


#include "../Actor/AmathProjectile.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AAmathProjectile::AAmathProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Scene = CreateDefaultSubobject<USceneComponent>("RootComponent");
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
	ProjectileMovementComponent->InitialSpeed = 200.f;
	ProjectileMovementComponent->MaxSpeed = 200.f;
	ProjectileMovementComponent->ProjectileGravityScale = 0;

	SetRootComponent(Scene);
	Mesh->SetupAttachment(Scene);
	Sphere->SetupAttachment(Mesh);
}

void AAmathProjectile::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

// Called when the game starts or when spawned
void AAmathProjectile::BeginPlay()
{
	Super::BeginPlay();
}

