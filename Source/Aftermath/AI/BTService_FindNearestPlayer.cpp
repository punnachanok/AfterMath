// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_FindNearestPlayer.h"
#include "AIController.h"
#include "BehaviorTree/BTFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

void UBTService_FindNearestPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* OwningPawn = AIOwner->GetPawn();
	
	TArray<AActor*> ActorsWithTag;
	UGameplayStatics::GetAllActorsWithTag(OwningPawn, FName("Player"), ActorsWithTag);

	float LowestDistance = 10000;
	AActor* ClosestActor = nullptr;
	for(AActor* Actor : ActorsWithTag)
	{
		float DistanceToTarget = Actor->GetDistanceTo(OwningPawn);
		if(LowestDistance > DistanceToTarget)
		{
			LowestDistance = DistanceToTarget;
			ClosestActor = Actor;
		}
		
		//GEngine->AddOnScreenDebugMessage(2, .5f, FColor::Orange, *Actor->GetName());
	}
	UBTFunctionLibrary::SetBlackboardValueAsObject(this, TargetToFollowSelector, ClosestActor);
	UBTFunctionLibrary::SetBlackboardValueAsFloat(this, DistanceToTargetSelector, LowestDistance);
}
