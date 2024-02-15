// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UserWidgetBase.h"
#include "MathProblems.generated.h"

class UEditableTextBox;
/**
 * 
 */
UCLASS()
class AFTERMATH_API UMathProblems : public UUserWidgetBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Meta = (BindWidget))
	UEditableTextBox* LeftAns;

	UPROPERTY(EditAnywhere, Meta = (BindWidget))
	UEditableTextBox* Question;

	UPROPERTY(EditAnywhere, Meta = (BindWidget))
	UEditableTextBox* RightAns;
};
