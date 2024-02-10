// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "AmathAIController.generated.h"

class UBehaviorTreeComponent;

UCLASS()
class AFTERMATH_API AAmathAIController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAmathAIController();

	//UPROPERTY()
	//TObjectPtr<UBlackboardComponent> BlackboardComponent;
	
	UPROPERTY()
	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;

};
