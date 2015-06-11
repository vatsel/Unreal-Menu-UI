// © 2015 Mark Vatsel

#pragma once

#include "Manipulators_01.h"
#include "Public/UI/MainMenuHUD.h"


class SMainMenuButton : public SCompoundWidget
{
	DECLARE_DELEGATE(FButtonClickedDelegate)
	TWeakObjectPtr<class AMainMenuHUD> OwnerHud;
	
	bool inactive = false; //greyed out
	bool hoverMode = false;	

	TAttribute<FText> buttonText;
	TAttribute<FSlateFontInfo> font;
	TAttribute<TOptional<bool>> inactiveInput;
	TAttribute<TOptional<FLinearColor>> textColour;
	TAttribute<TOptional<FLinearColor>> hoverTextColour;
	TAttribute<TOptional<FButtonClickedDelegate>> mouseClickedDelegate;

	FSlateColor GetTextColour() const;
	virtual FReply OnMouseButtonDown(const FGeometry& aGeometry, const FPointerEvent& mouseEvent) override;
	virtual void OnMouseEnter(const FGeometry& aGeometry, const FPointerEvent& mouseEvent) override;
	virtual void OnMouseLeave(const FPointerEvent& mouseEvent) override;
	
public:
	SLATE_BEGIN_ARGS(SMainMenuButton)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, OwnerHud)
	SLATE_ARGUMENT(FText, buttonText)
	SLATE_ARGUMENT(FSlateFontInfo, font)
	SLATE_ARGUMENT(TOptional<bool>, inactiveInput)
	SLATE_ARGUMENT(TOptional<FLinearColor>, textColour) 
	SLATE_ARGUMENT(TOptional<FLinearColor>,hoverTextColour)
	SLATE_ARGUMENT(FButtonClickedDelegate, mouseClickedDelegate)

	SLATE_EVENT(FOnClicked, buttonClickedEvent)

	SLATE_END_ARGS()

	FOnClicked buttonClickedEvent;
	void Construct(const FArguments& inArgs);
};