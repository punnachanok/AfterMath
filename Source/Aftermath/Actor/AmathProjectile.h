// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AmathProjectile.generated.h"

class UProjectileMovementComponent;
class USphereComponent;

UCLASS()
class AFTERMATH_API AAmathProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAmathProjectile();

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	UProjectileMovementComponent* ProjectileMovementComponent;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void OnSphereOverlap();
	

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;

	TObjectPtr<USceneComponent> Scene;
};
