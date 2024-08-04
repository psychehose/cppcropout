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
	UCropoutGameInstance();


	virtual void Init() override;


	// Save, Load 추후 구현

	//UFUNCTION()
	//void LoadGame();


	// Transition the game instance in
	UFUNCTION()
	void TransitionIn();

	// Transition the game instance out
	UFUNCTION()
	void TransitionOut();

	// Set the start game offset
	UFUNCTION()
	void SetStartGameOffset(double InGameTime);

	// Get the start game offset
	UFUNCTION()
	double GetStartGameOffset();

private:
	double StartGameOffset;

	UPROPERTY()
	class UUserWidget* UI_Transition;

	
};
