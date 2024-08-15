// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CropoutGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

#include "UI/UI_Transition.h"

UCropoutGameInstance::UCropoutGameInstance()
{
	StartGameOffset = 0.0f;

    static ConstructorHelpers::FClassFinder<UUI_Transition> TransitionWidgetClassFinder(TEXT("/Game/UI/UI_Transition"));
    if (TransitionWidgetClassFinder.Succeeded())
    {
        TSubclassOf<UUserWidget> TransitionWidgetClass = TransitionWidgetClassFinder.Class;
    }
}

void UCropoutGameInstance::Init()
{
	Super::Init();

}

void UCropoutGameInstance::TransitionIn()
{

    if (!UI_Transition && UI_TransitionClass)
    {
		UI_Transition = CreateWidget<UUI_Transition>(this, UI_TransitionClass);
    }


    if (UI_Transition)
    {
        if (!UI_Transition->IsInViewport())
        {
			UI_Transition->AddToViewport();
		}

        // Animate the transition in

        UI_Transition->TransitionIn();
    }
}

void UCropoutGameInstance::TransitionOut()
{
}

void UCropoutGameInstance::SetStartGameOffset(double InGameTime)
{
	StartGameOffset = InGameTime;
}

double UCropoutGameInstance::GetStartGameOffset()
{
	return StartGameOffset;
}

void UCropoutGameInstance::OpenLevel(TSoftObjectPtr<UWorld> Level)
{
    TransitionIn();

    GetWorld()->GetTimerManager().SetTimer(OpenLevelTimerHandle, [this, Level]()
    {
		OpenLevel_Internal(Level);
	}, 1.1f, false);
    
}

void UCropoutGameInstance::OpenLevel_Internal(TSoftObjectPtr<UWorld> Level)
{
    UGameplayStatics::OpenLevelBySoftObjectPtr(this, Level, true);
}
