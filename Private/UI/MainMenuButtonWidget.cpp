// © 2015 Mark Vatsel

#include "Manipulators_01.h"
#include "Public/UI/MainMenu/MainMenuButtonWidget.h"
#include "Public/UI/ManipulatorsStyle.h"
#include "Public/UI/MainMenu/MainMenuHUD.h"


void SMainMenuButton::Construct(const FArguments& inArgs)
{
	OwnerHud = inArgs._OwnerHud;
	buttonText = inArgs._buttonText;
	font = inArgs._font;
	inactiveInput = inArgs._inactiveInput;
	inactiveTextColour = inArgs._inactiveTextColour;
	textColour = inArgs._textColour;
	buttonClickedEvent = inArgs._buttonClickedEvent;
	hoverTextColour = inArgs._hoverTextColour;
	

	if (inactiveInput.Get().IsSet()) inactive = inactiveInput.Get().GetValue();
	
	ChildSlot
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.ColorAndOpacity(this,&SMainMenuButton::GetTextColour)
			.Text(buttonText)
			.Font(font)
		];
}

FSlateColor SMainMenuButton::GetTextColour() const
{
	if (inactive) return inactiveTextColour.Get().IsSet() ? inactiveTextColour.Get().GetValue() : FLinearColor(0.25f, 0.25f, 0.25f);
	else
	{
		if (hoverMode) return hoverTextColour.Get().IsSet() ? hoverTextColour.Get().GetValue() : FLinearColor(0.f, 0.843f, 1.f);
		else return textColour.Get().IsSet() ? textColour.Get().GetValue() : FLinearColor::White;
	}
}

FReply SMainMenuButton::OnMouseButtonDown(const FGeometry& aGeometry, const FPointerEvent& mouseEvent)
{	
	if (buttonClickedEvent.IsBound()) return buttonClickedEvent.Execute();
	return FReply::Handled();
}

void SMainMenuButton::OnMouseEnter(const FGeometry& aGeometry, const FPointerEvent& mouseEvent)
{
	if (!inactive) hoverMode = true;
}

void SMainMenuButton::OnMouseLeave(const FPointerEvent& mouseEvent)
{
	if (!inactive) hoverMode = false;
}