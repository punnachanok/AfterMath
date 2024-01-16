// Fill out your copyright notice in the Description page of Project Settings.


#include "../Actor/AftermathEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Aftermath/GameplayAbility/AftermathAttributeSet.h"
#include "Components/SphereComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayEffectTypes.h"

// Sets default values
AAftermathEffectActor::AAftermathEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	
	// Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	// Sphere->SetupAttachment(GetRootComponent());

}

// void AAftermathEffectActor::OnOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
// 	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
// {
// 	if(IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
// 	{
// 		const UAftermathAttributeSet* AftermathAttributeSet = Cast<UAftermathAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UAftermathAttributeSet::StaticClass()));
//
// 		UAftermathAttributeSet* MutableAftermathAttributeSet = const_cast<UAftermathAttributeSet*>(AftermathAttributeSet);
// 		MutableAftermathAttributeSet->SetHealth(AftermathAttributeSet->GetHealth() + 25.f);
// 		Destroy();
// 	}
// 	
// 	
// 	
// }

// void AAftermathEffectActor::EndOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
// 	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
// {
// }



// Called when the game starts or when spawned
void AAftermathEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	// Sphere->OnComponentBeginOverlap.AddDynamic(this, &AAftermathEffectActor::OnOverLap);
}

void AAftermathEffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if(TargetASC == nullptr) return;

	checkf(GameplayEffectClass, TEXT("U forgot to include GE_Effect lol :P"))

	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.f, EffectContextHandle);
	TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}
