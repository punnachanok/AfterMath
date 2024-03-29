// Fill out your copyright notice in the Description page of Project Settings.


#include "../Character/EnemyCharacter.h"

#include "AbilitySystemComponent.h"
#include "Aftermath/AI/AmathAIController.h"
#include "Aftermath/GameplayAbility/AftermathAbilitySystemComponent.h"
#include "Aftermath/GameplayAbility/AftermathAttributeSet.h"
#include "Aftermath/GameplayAbility/AMathGameplayAbility.h"
#include "Aftermath/UI/OverlayWidgetController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

AEnemyCharacter::AEnemyCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAftermathAbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<UAftermathAttributeSet>("Attribute Set");

	const UAftermathAttributeSet* AMathAttributeSet = CastChecked<UAftermathAttributeSet>(AttributeSet);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	AMathAttributeSet->GetHealthAttribute()).AddUObject(this, &AEnemyCharacter::HealthChanged);

	Tags.Add("Enemy");
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this,  this);
}

void AEnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	AmathAIController = Cast<AAmathAIController>(NewController);
	AmathAIController->GetBlackboardComponent()->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
	AmathAIController->RunBehaviorTree(BehaviorTree);
}

void AEnemyCharacter::HealthChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged.Broadcast(Data.NewValue);
	FString FloatAsString = FString::Printf(TEXT("%f"), Data.NewValue);
	if(Data.NewValue <= 0)
	{
		Die();
		IsDead = true;
	}
}

void AEnemyCharacter::EnemyAttack()
{
	if(IsDead) return;
	
	if(AbilitySystemComponent)
	{
		if (EnemyAttackAbility)
		{
			FRotator EnemyRotation;
			TArray<AActor*> ActorsWithTag;
			UGameplayStatics::GetAllActorsWithTag(this, FName("Player"), ActorsWithTag);
			float LowestDistance = 10000;
			AActor* ClosestActor = nullptr;

			for(AActor* Actor : ActorsWithTag)
			{
				float DistanceToTarget = this->GetDistanceTo(Actor);
				if(LowestDistance > DistanceToTarget)
				{
					LowestDistance = DistanceToTarget;
					ClosestActor = Actor;
				}
			}

			if(ClosestActor)
			{
				EnemyRotation =  UKismetMathLibrary::FindLookAtRotation(this->GetActorLocation(), ClosestActor->GetActorLocation());
				this->SetActorRotation(EnemyRotation);
			}
			
			FGameplayAbilitySpecDef AbilitySpecDef = FGameplayAbilitySpecDef();
			AbilitySpecDef.Ability = EnemyAttackAbility;

			FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilitySpecDef, 1);
			AbilitySystemComponent->GiveAbilityAndActivateOnce(AbilitySpec);
			
		}
	}
}