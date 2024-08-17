// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CropoutGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CPPCROPOUT_API ACropoutGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACropoutGameMode();

	virtual void BeginPlay() override;

private:
	
	// Set the start game offset
	void SetStartGameOffset();

	void ClearRenderTarget();
	
	UPROPERTY()
	class UCropoutGameInstance* GameInstance;

	UPROPERTY(EditDefaultsOnly, Category = "Rendering");
	class UTextureRenderTarget2D* GrassMoveRenderTarget;

	UPROPERTY(EditDefaultsOnly, Category = "Rendering");
	FLinearColor ClearColor;


};
