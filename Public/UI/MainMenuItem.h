// © 2015 Mark Vatsel

#pragma once
#include "Manipulators_01.h"
#include "Public/UI/MainMenu/MainMenuButtonWidget.h"
#include "Public/EnumTypes.h"

/** Stores information about an SMainMenuButton. Useful to create the data prior to a widget's Construct()
*/
class FMainMenuItem
{
	bool inactive;
	FText text;
	MainMenuItem menuType;

public:
	DECLARE_DELEGATE(FOnButtonClicked);

	FOnButtonClicked onButtonClicked;
	TSharedPtr<class SMainMenuButton> widget;

	MainMenuItem GetType() const { return menuType; }
	FText GetText() const { return text; }
	bool IsInactive() const { return inactive;  }

	FMainMenuItem(FText _text, MainMenuItem type, bool _inactive = false);
};