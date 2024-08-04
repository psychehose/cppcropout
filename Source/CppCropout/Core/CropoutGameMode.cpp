// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CropoutGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Core/CropoutGameInstance.h"

ACropoutGameMode::ACropoutGameMode()
{
	ClearColor = FLinearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void ACropoutGameMode::BeginPlay()
{
	Super::BeginPlay();

	GameInstance = Cast<UCropoutGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	TransitionOut();
}

void ACropoutGameMode::TransitionOut()
{
	if (GameInstance)
	{
		GameInstance->TransitionOut();
	}

	SetStartGameOffset();
}

void ACropoutGameMode::SetStartGameOffset()
{
	if (GameInstance)
	{
		double GameTime = UGameplayStatics::GetTimeSeconds(GetWorld());
		GameInstance->SetStartGameOffset(GameTime);
	}

	ClearRenderTarget();
}

void ACropoutGameMode::ClearRenderTarget()
{
	if (GrassMoveRenderTarget)
	{
		UKismetRenderingLibrary::ClearRenderTarget2D(this, GrassMoveRenderTarget, ClearColor);
	}
}
