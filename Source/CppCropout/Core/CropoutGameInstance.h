// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CropoutGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CPPCROPOUT_API UCropoutGameInstance : public UGameInstance
{
	GENERATED_BODY()


public:
	UCropoutGameInstance(const FObjectInitializer& ObjectInitializer);


	virtual void Init() override;

	// Set the start game offset
	void SetStartGameOffset(double InGameTime);

	// Get the start game offset
	double GetStartGameOffset();

	// Open a level
	void OpenLevel(TSoftObjectPtr<UWorld> Level);

	// Transition the game instance in
	void TransitionIn();

	// Transition the game instance out
	void TransitionOut();


private:
	void OpenLevel_Internal(TSoftObjectPtr<UWorld> Level);

	FTimerHandle OpenLevelTimerHandle;

private:
	double StartGameOffset;

	UPROPERTY()
	TSubclassOf<class UUI_Transition> UI_TransitionClass;

	UPROPERTY()
	TObjectPtr<class UUI_Transition> UI_Transition;
};
