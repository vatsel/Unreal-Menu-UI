// © 2015 Mark Vatsel

#pragma once
#include "SlateWidgetStyleContainerBase.h"
#include "MainMenuWidgetStyle.generated.h"

/**
*
*/

USTRUCT()
struct FMainMenuStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()
	
	FMainMenuStyle();
	virtual ~FMainMenuStyle();
	virtual void GetResources(TArray <const FSlateBrush*> &outBrushes) const override;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FMainMenuStyle& GetDefault();
	static const FName TypeName;
	
	UPROPERTY(EditAnywhere, Category = General)
		TEnumAsByte<EVerticalAlignment> containerVerticalAlignment = TEnumAsByte<EVerticalAlignment>(EVerticalAlignment::VAlign_Center);

	UPROPERTY(EditAnywhere, Category = General)
		TEnumAsByte<EHorizontalAlignment> containerHorizontalAlignment = TEnumAsByte<EHorizontalAlignment>(EHorizontalAlignment::HAlign_Center);

	UPROPERTY(EditAnywhere, Category = Background)
		FSlateBrush backgroundBrush;	

	UPROPERTY(EditAnywhere, Category = Appearance)
		FLinearColor textColour = FLinearColor::White;

	UPROPERTY(EditAnywhere, Category = Appearance)
		FLinearColor inactiveTextColour = FLinearColor(0.3f,0.3f,0.3f);

	UPROPERTY(EditAnywhere, Category = MenuItems)
		float menuItemsPadding = 5.0f;

	UPROPERTY(EditAnywhere, Category = Title)
		float titlePadding = 44.f;

	UPROPERTY(EditAnywhere, Category = Title)
		float titleUnderlineBottomPadding = 44.f;

	UPROPERTY(EditAnywhere, Category = Title)
		FVector2D titleUnderlineSize = FVector2D(550.f, 1.5f);

	UPROPERTY(EditAnywhere, Category = Title)
		FText titleText = FText::FromString("START");

	UPROPERTY(EditAnywhere, Category = ExitButton)
		float exitButtonPadding = 40.f;

};



UCLASS(hidecategories=Object, MinimalAPI)
class UMainMenuWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_UCLASS_BODY()

public:
	const struct FSlateWidgetStyle * const GetStyle() const override;		

	UPROPERTY(Category = Appearance, EditAnywhere, meta = (ShowOnlyInnerProperties))
		FMainMenuStyle menuStyle;	
};
