// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "AmathAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class AFTERMATH_API UAmathAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	UAmathAssetManager& Get();
	virtual void StartInitialLoading() override;
};
