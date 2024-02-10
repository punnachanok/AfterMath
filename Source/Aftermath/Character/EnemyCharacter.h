// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Character/AftermathCharacterBase.h"
#include "EnemyCharacter.generated.h"

class UBehaviorTree;
class AAmathAIController;
class AAIController;
struct FOnAttributeChangeData;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyHealthChangedSignature, float, NewEnemyHealth);

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

DECLARE_MULTICAST_DELEGATE_OneParam(OnEnemyHealthChangedDelegate, float)


/**
 * s
 */
UCLASS()
class AFTERMATH_API AEnemyCharacter : public AAftermathCharacterBase
{
	GENERATED_BODY()

public:
	AEnemyCharacter();

	virtual void BeginPlay() override;

	virtual void PossessedBy(AController* NewController) override;
	
	UPROPERTY(BlueprintAssignable);
	FOnEnemyHealthChangedSignature OnHealthChanged;
	
	void HealthChanged(const FOnAttributeChangeData& Data);

	UPROPERTY(EditAnywhere, Category = "AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;
	
	UPROPERTY(EditAnywhere, Category = "AI")
	TObjectPtr<AAmathAIController> AmathAIController;
	
	OnEnemyHealthChangedDelegate OnEnemyHealthChanged;
	
};