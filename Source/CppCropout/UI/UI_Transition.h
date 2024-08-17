// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_Transition.generated.h"

/**
 * 
 */
UCLASS()
class CPPCROPOUT_API UUI_Transition : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Transition")
	void TransitionIn();
	UFUNCTION(BlueprintImplementableEvent, Category = "Transition")
	void TransitionOut();


	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCommonTextBlock> Loading_TextBlock;

	
};
