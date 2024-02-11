// Fill out your copyright notice in the Description page of Project Settings.


#include "../Actor/AmathProjectile.h"

#include "AbilitySystemInterface.h"
#include "Aftermath/GameplayAbility/AftermathAttributeSet.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAmathProjectile::AAmathProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Scene = CreateDefaultSubobject<USceneComponent>("RootComponent");

	SetRootComponent(Scene);
	Mesh->SetupAttachment(Scene);
	Sphere->SetupAttachment(Mesh);
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AAmathProjectile::OnOverLap);
	
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
	ProjectileMovementComponent->InitialSpeed = 200.f;
	ProjectileMovementComponent->MaxSpeed = 200.f;
	ProjectileMovementComponent->ProjectileGravityScale = 0;

	SetLifeSpan(4.0f);
}

void AAmathProjectile::OnOverLap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Emerald, "Projectile Overlap");

	if(IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
		{
			const UAftermathAttributeSet* AftermathAttributeSet = Cast<UAftermathAttributeSet>(
			ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UAftermathAttributeSet::StaticClass()));

			UAftermathAttributeSet* MutableAftermathAttributeSet = const_cast<UAftermathAttributeSet*>(
			AftermathAttributeSet);
			MutableAftermathAttributeSet->SetHealth(AftermathAttributeSet->GetHealth() - 25.f);
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ImpactEffect, this->GetActorLocation());
			UGameplayStatics::PlaySoundAtLocation(this, ImpactAudio, this->GetActorLocation(), FRotator::ZeroRotator, 0.5);
		}
	
	
	this->Destroy();
}

// Called when the game starts or when spawned
void AAmathProjectile::BeginPlay()
{
	Super::BeginPlay();
}

