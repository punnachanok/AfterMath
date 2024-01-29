// Fill out your copyright notice in the Description page of Project Settings.


#include "AmathAssetManager.h"

#include "Misc/AmathGameplayTags.h"

UAmathAssetManager& UAmathAssetManager::Get()
{
	check(GEngine);


	UAmathAssetManager* AmathAssetManager = Cast<UAmathAssetManager>(GEngine->AssetManager);

	return *AmathAssetManager;
}

void UAmathAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FAmathGameplayTags::InitializeNativeGameplayTags();
}
