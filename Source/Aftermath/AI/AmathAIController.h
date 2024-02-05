// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "AmathAIController.generated.h"

UCLASS()
class AFTERMATH_API AAmathAIController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAmathAIController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
