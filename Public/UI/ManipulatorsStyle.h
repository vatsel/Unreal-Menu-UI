// © 2015 Mark Vatsel, adapted from an example by Epic Games, Inc.

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"

/**
* Holds the various style sets. Registers/ unregisters found UWidgetStyleSets as part of the Hot Reload hack
*/
class FManipulatorsStyle
{
	static TSharedPtr <class FSlateStyleSet> manipulatorsStyleInstance;

public:
	static const FName styleSetName;
	static void Initialize();
	static void Shutdown();
	static const ISlateStyle& Get();
};
