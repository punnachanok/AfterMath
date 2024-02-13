// Fill out your copyright notice in the Description page of Project Settings.


#include "AmathHomingProjectile.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "NiagaraFunctionLibrary.h"
#include "Aftermath/GameplayAbility/AftermathAttributeSet.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AAmathHomingProjectile::AAmathHomingProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Scene = CreateDefaultSubobject<USceneComponent>("RootComponent");

	SetRootComponent(Scene);
	Mesh->SetupAttachment(Scene);
	Sphere->SetupAttachment(Mesh);
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AAmathHomingProjectile::OnOverLap);
	
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
	ProjectileMovementComponent->InitialSpeed = 200.f;
	ProjectileMovementComponent->MaxSpeed = 200.f;
	ProjectileMovementComponent->ProjectileGravityScale = 0;
	ProjectileMovementComponent->bIsHomingProjectile = true;
	//ProjectileMovementComponent->HomingTargetComponent = 

	Mesh->SetCollisionResponseToAllChannels(ECR_Ignore);
		SetLifeSpan(4.0f);
	}

void AAmathHomingProjectile::OnOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor->Tags.Contains(ActorSide)) return;
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
}

// Called when the game starts or when spawned
void AAmathHomingProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}
