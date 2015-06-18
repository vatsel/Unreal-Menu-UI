// © 2015 Mark Vatsel

#pragma once

#include "MainMenuHUD.h"
#include "SlateBasics.h"
#include "Public/EnumTypes.h"


class SMainMenuWidget : public SCompoundWidget 
{

	SLATE_BEGIN_ARGS(SMainMenuWidget)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, ownerHUD)
	SLATE_END_ARGS()
		
	TWeakObjectPtr<AMainMenuHUD> ownerHUD;
	const struct FMainMenuStyle *menuWidgetStyle;
	TSharedPtr<SVerticalBox> buttonBox;
	
	/** Calls other functions to create specific widgets and appends them to buttonBox.*/
	void BuildMainMenu(TSharedPtr<TArray<class FMainMenuItem>> menuToBuild);

	/** Also creates a small SColorBox as an underline*/
	void BuildTitle(FMainMenuItem& menuItem, int buttonIndex=0);
	void BuildOption(FMainMenuItem& menuItem, int buttonIndex);
	void BuildEnd(FMainMenuItem& menuItem, int buttonIndex);
	
	FReply PressButton(int index);

	DECLARE_DELEGATE(FButtonClickedDelegate)
	FOnClicked buttonClickedEvent;

public:
	void Construct(const FArguments& InArgs);
	
	virtual FReply OnFocusReceived(const FGeometry& aGeometry, const FFocusEvent& inFocusEvent) override;
	virtual bool SupportsKeyboardFocus() const override { return true; }
};