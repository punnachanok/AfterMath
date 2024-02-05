// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SecondMissile.generated.h"

class UProjectileMovementComponent;
class USphereComponent;
class UNiagaraComponent;

UCLASS()
class AFTERMATH_API ASecondMissile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASecondMissile();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	UProjectileMovementComponent* ProjectileMovementComponent;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UNiagaraComponent> Niagara;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USceneComponent> Scene;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USphereComponent> Sphere;
public:

};
