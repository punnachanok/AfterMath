// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Character/AftermathCharacterBase.h"
#include "FriendCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AFTERMATH_API AFriendCharacter : public AAftermathCharacterBase
{
	GENERATED_BODY()

public:
	AFriendCharacter();

	virtual void BeginPlay() override;
};
