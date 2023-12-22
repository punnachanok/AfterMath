// Fill out your copyright notice in the Description page of Project Settings.


#include "../Character/EnemyCharacter.h"

#include "AbilitySystemComponent.h"

AEnemyCharacter::AEnemyCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);
	
	AttributeSet = CreateDefaultSubobject<UAttributeSet>("Attribute Set");
}
