// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CropoutGameInstance.h"
#include "Blueprint/UserWidget.h"

UCropoutGameInstance::UCropoutGameInstance()
{
}

void UCropoutGameInstance::Init()
{
	Super::Init();

	// Crate UI_Transition
    static ConstructorHelpers::FClassFinder<UUserWidget> TransitionWidgetClassFinder(TEXT("/Game/UI/UI_Transition"));
    if (TransitionWidgetClassFinder.Succeeded())
    {
        TSubclassOf<UUserWidget> TransitionWidgetClass = TransitionWidgetClassFinder.Class;
        if (TransitionWidgetClass != nullptr)
        {
            // Create the UI_Transition widget
            UI_Transition = CreateWidget<UUserWidget>(this, TransitionWidgetClass);
            if (UI_Transition)
            {
                // we can Add the UI_Transition widget to the viewport
            }
        }
    }

}

void UCropoutGameInstance::TransitionIn()
{
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
