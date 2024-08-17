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
	UE_LOG(LogTemp, Warning, TEXT("ACropoutGameMode::BeginPlay()"));
	Super::BeginPlay();

	GameInstance = Cast<UCropoutGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	GameInstance->TransitionOut();

	SetStartGameOffset();

	ClearRenderTarget();

}

void ACropoutGameMode::SetStartGameOffset()
{
	if (GameInstance)
	{
		double GameTime = UGameplayStatics::GetTimeSeconds(GetWorld());
		GameInstance->SetStartGameOffset(GameTime);
	}
}

void ACropoutGameMode::ClearRenderTarget()
{
	if (GrassMoveRenderTarget)
	{
		UKismetRenderingLibrary::ClearRenderTarget2D(this, GrassMoveRenderTarget, ClearColor);
	}
}
