// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AmathHomingProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UNiagaraSystem;

UCLASS()
class AFTERMATH_API AAmathHomingProjectile : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AAmathHomingProjectile();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	UProjectileMovementComponent* ProjectileMovementComponent;

	UFUNCTION()
	void OnOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
	//void AAftermathEffectActor::OnOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	// 	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY()
	TObjectPtr<USceneComponent> Scene;

	UPROPERTY(EditAnywhere, Category = "Niagara")
	TObjectPtr<UNiagaraSystem> ImpactEffect;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USoundBase> ImpactAudio;

	UPROPERTY(EditAnywhere, Category = "ActorSide")
	FName ActorSide;
};
