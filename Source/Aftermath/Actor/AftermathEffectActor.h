// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "GameFramework/Actor.h"
#include "AftermathEffectActor.generated.h"

class USphereComponent;

UCLASS()
class AFTERMATH_API AAftermathEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAftermathEffectActor();

	// UFUNCTION()
	// virtual void OnOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,bool bFromSweep, const FHitResult& SweepResult);

	// UFUNCTION()
	// virtual void EndOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GameplayEffect")
	TSubclassOf<UGameplayEffect> InstantEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GameplayEffect")
	TSubclassOf<UGameplayEffect> DurationEffect;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
private:
	// UPROPERTY(VisibleAnywhere)
	// TObjectPtr<USphereComponent> Sphere;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;
};
