// © 2015 Mark Vatsel

#include "Manipulators_01.h"
#include "Public/UI/MainMenu/MainMenuWidgetStyle.h"
#include "Public/UI/ManipulatorsStyle.h"

FMainMenuStyle::FMainMenuStyle(){}
FMainMenuStyle::~FMainMenuStyle(){}

const FMainMenuStyle& FMainMenuStyle::GetDefault()
{
	static FMainMenuStyle _default;
	return _default;
}

const FName FMainMenuStyle::TypeName(TEXT("FMainMenuStyle"));

void FMainMenuStyle::GetResources(TArray <const FSlateBrush*> &outBrushes) const
{
	outBrushes.Add(&backgroundBrush);
}

UMainMenuWidgetStyle::UMainMenuWidgetStyle(const FObjectInitializer& objectInitializer) : Super(objectInitializer){}

const struct FSlateWidgetStyle* const UMainMenuWidgetStyle::GetStyle() const
{
	return static_cast<const struct FSlateWidgetStyle* >( &menuStyle );
}