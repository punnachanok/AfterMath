// Fill out your copyright notice in the Description page of Project Settings.


#include "../Character/FriendCharacter.h"

#include "AbilitySystemComponent.h"

AFriendCharacter::AFriendCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);
	
	AttributeSet = CreateDefaultSubobject<UAttributeSet>("Attribute Set");
}


