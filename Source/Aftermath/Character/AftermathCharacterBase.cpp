// Fill out your copyright notice in the Description page of Project Settings.


#include "AftermathCharacterBase.h"

#include "Aftermath/GameplayAbility/AftermathAbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AAftermathCharacterBase::AAftermathCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(GetMesh(), "WeaponSocket");
}

UAbilitySystemComponent* AAftermathCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AAftermathCharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}

void AAftermathCharacterBase::AddCharacterAbilities()
{
	
	UAftermathAbilitySystemComponent* AMathASC = CastChecked<UAftermathAbilitySystemComponent>(AbilitySystemComponent);
	if(!HasAuthority()) return;

	AMathASC->AddCharacterAbilities(StartupAbilities);
}

void AAftermathCharacterBase::Die()
{
	UPhysicsAsset* physAsset = GetMesh()->GetPhysicsAsset();
	if (physAsset != nullptr)
	{
		GetMesh()->SetSimulatePhysics(true);
		GetMesh()->WakeAllRigidBodies();

		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

		GetMesh()->SetCollisionProfileName(TEXT("Ragdoll"));

		SetLifeSpan(5);
	}
}
