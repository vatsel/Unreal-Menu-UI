// © 2015 Mark Vatsel 
// Adapted from an example by Epic Games, Inc.


#include "Manipulators_01.h"
#include "Public/UI/ManipulatorsStyle.h"
#include "SlateGameResources.h"



TSharedPtr <FSlateStyleSet> FManipulatorsStyle::manipulatorsStyleInstance = NULL;
const FName FManipulatorsStyle::styleSetName = TEXT("ManipulatorsStyle");

void FManipulatorsStyle::Initialize()
{
	if (!manipulatorsStyleInstance.IsValid())
	{
		TSharedRef<FSlateStyleSet> manipulatorsStyleReference = FSlateGameResources::New(styleSetName, "/Game/UI/Styles", "/Game/UI/Styles");
		FSlateStyleSet& styleSet = manipulatorsStyleReference.Get();

		styleSet.Set("Manipulators.MenuTitleFont", FSlateFontInfo(FPaths::GameContentDir() / "Fonts/Montserrat-Hairline.ttf", 60));
		styleSet.Set("Manipulators.MenuSubTitleFont", FSlateFontInfo(FPaths::GameContentDir() / "Fonts/Montserrat-Hairline.ttf", 42));
		styleSet.Set("Manipulators.MenuExitFont", FSlateFontInfo(FPaths::GameContentDir() / "Fonts/Montserrat-Hairline.ttf", 35));
		styleSet.Set("Manipulators.DefaultFont", FSlateFontInfo(FPaths::GameContentDir() / "Fonts/Montserrat-Hairline.ttf", 30));
		
		manipulatorsStyleInstance = manipulatorsStyleReference;
		FSlateStyleRegistry::RegisterSlateStyle(*manipulatorsStyleInstance);	
	}
}

void FManipulatorsStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*manipulatorsStyleInstance);
	ensure(manipulatorsStyleInstance.IsUnique());
	manipulatorsStyleInstance.Reset();
}

const ISlateStyle& FManipulatorsStyle::Get()
{
	return *manipulatorsStyleInstance;
}