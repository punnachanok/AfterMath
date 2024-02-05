// Fill out your copyright notice in the Description page of Project Settings.


#include "../Character/EnemyCharacter.h"

#include "AbilitySystemComponent.h"
#include "Aftermath/GameplayAbility/AftermathAbilitySystemComponent.h"
#include "Aftermath/GameplayAbility/AftermathAttributeSet.h"
#include "Aftermath/UI/OverlayWidgetController.h"

AEnemyCharacter::AEnemyCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAftermathAbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<UAftermathAttributeSet>("Attribute Set");

	const UAftermathAttributeSet* AMathAttributeSet = CastChecked<UAftermathAttributeSet>(AttributeSet);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	AMathAttributeSet->GetHealthAttribute()).AddUObject(this, &AEnemyCharacter::HealthChanged);
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this,  this);
}

void AEnemyCharacter::HealthChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged.Broadcast(Data.NewValue);
	FString FloatAsString = FString::Printf(TEXT("%f"), Data.NewValue);
	if(Data.NewValue <= 0)
	{
		Die();
	}
}