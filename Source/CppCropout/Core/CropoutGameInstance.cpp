// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CropoutGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "UI/UI_Transition.h"

UCropoutGameInstance::UCropoutGameInstance(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
	StartGameOffset = 0.0f;

    static ConstructorHelpers::FClassFinder<UUI_Transition> TransitionWidgetClassFinder(TEXT("/Game/UI/UI_Transition.UI_Transition_C"));
    if (TransitionWidgetClassFinder.Succeeded())
    {
        UI_TransitionClass = TransitionWidgetClassFinder.Class;
    }
}

void UCropoutGameInstance::Init()
{
	Super::Init();

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

void UCropoutGameInstance::TransitionIn()
{
    UE_LOG(LogTemp, Warning, TEXT("TransitionIn"));

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
    UE_LOG(LogTemp, Warning, TEXT("TransitionOut"));

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

        // Animate the transition out
        UI_Transition->TransitionOut();
    }
}