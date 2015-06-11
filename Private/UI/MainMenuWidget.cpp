// © 2015 Mark Vatsel

#include "Manipulators_01.h"
#include "Public/UI/MainMenuWidget.h"
#include "Public/UI/MainMenuWidgetStyle.h"
#include "Public/UI/MainMenuButtonWidget.h"
#include "SlateGameResources.h"
#include "Public/UI/ManipulatorsStyle.h"

void SMainMenuWidget::Construct(const FArguments& InArgs)
{
	menuWidgetStyle = &FManipulatorsStyle::Get().GetWidgetStyle<FMainMenuStyle>("MainMenuWidgetStyle");
	buttonsBuilt = false;
	ownerHUD = InArgs._ownerHUD;
	
	ChildSlot
		.VAlign( VAlign_Center)
		.HAlign( HAlign_Center)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.VAlign( VAlign_Fill)
			.HAlign( HAlign_Fill)
			[
				SNew(SColorBlock)
				.Color(FLinearColor::Black)
			]
			
			+ SOverlay::Slot()
			.VAlign( VAlign_Center)
			.HAlign( HAlign_Center)
				[

					SNew(SImage)
					.Image(&menuWidgetStyle->backgroundBrush)
				]
			+ SOverlay::Slot()
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Center)
				[
					SAssignNew(buttonBox, SVerticalBox)
				]			
		];

	BuildMainMenu(ownerHUD->menu);
}

FReply SMainMenuWidget::OnFocusReceived(const FGeometry& aGeometry, const FFocusEvent& inFocusEvent)
{
	return FReply::Handled().LockMouseToWidget(SharedThis(this));
}

FReply SMainMenuWidget::PressButton(int index)
{
	FMainMenuItem menuButton = (*ownerHUD->GetMenu())[index];
	if (menuButton.onButtonClicked.IsBound())
	{
		menuButton.onButtonClicked.Execute();
		return FReply::Handled();
	}
	return FReply::Unhandled();
}

void SMainMenuWidget::BuildTitle(FMainMenuItem& menuItem, int buttonIndex)
{	
	TSharedPtr<SMainMenuButton> throwawayButton = SAssignNew(menuItem.widget, SMainMenuButton)
		.buttonText(menuItem.GetText())
		.font(FManipulatorsStyle::Get().GetFontStyle("Manipulators.MenuTitleFont"))
		.buttonClickedEvent(this,&SMainMenuWidget::PressButton,buttonIndex);

	buttonBox->AddSlot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.AutoHeight()
		.Padding(menuWidgetStyle->titlePadding)
		[
			throwawayButton.ToSharedRef()
		];
	buttonBox->AddSlot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.AutoHeight()
		.Padding(FMargin(0.f, 0.f, 0.f, menuWidgetStyle->titleUnderlineBottomPadding))
		[
			SNew(SColorBlock)
			.Color(menuWidgetStyle->textColour)
			.Size(menuWidgetStyle->titleUnderlineSize)
		];
}

void SMainMenuWidget::BuildOption(FMainMenuItem& menuItem, int buttonIndex) 
{
	TSharedPtr<SMainMenuButton> throwawayButton = SAssignNew(menuItem.widget, SMainMenuButton)
		.buttonText(menuItem.GetText())
		.font(FManipulatorsStyle::Get().GetFontStyle("Manipulators.MenuSubtitleFont"))
		.inactiveInput(menuItem.IsInactive())
		.buttonClickedEvent(this, &SMainMenuWidget::PressButton, buttonIndex);

	buttonBox->AddSlot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.AutoHeight()
		.Padding(menuWidgetStyle->menuItemsPadding)
		[
			throwawayButton.ToSharedRef()
		];
}

void SMainMenuWidget::BuildEnd(FMainMenuItem& menuItem, int buttonIndex)
{
	TSharedPtr<SMainMenuButton> throwawayButton = SAssignNew(menuItem.widget, SMainMenuButton)
		.buttonText(menuItem.GetText())
		.font(FManipulatorsStyle::Get().GetFontStyle("Manipulators.MenuExitFont"))
		.buttonClickedEvent(this, &SMainMenuWidget::PressButton, buttonIndex);

	buttonBox->AddSlot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.AutoHeight()
		.Padding(menuWidgetStyle->exitButtonPadding)
		[
			throwawayButton.ToSharedRef()
		];
}

void SMainMenuWidget::BuildMainMenu(TSharedPtr<TArray<FMainMenuItem>> menuToBuild)
{
	for (int i = 0; i < menuToBuild.Get()->Num(); ++i)
	{
		MainMenuItem type = (*menuToBuild.Get())[i].GetType();
		if (type == MainMenuItem::Title)		BuildTitle((*menuToBuild.Get())[i], i);
		else if (type == MainMenuItem::Option)  BuildOption((*menuToBuild.Get())[i],i);
		else if (type == MainMenuItem::End)		BuildEnd((*menuToBuild.Get())[i], i);
		else UE_LOG(SlateDebug, Warning, TEXT("Unknown type of enum MainMenuItem, skipped building button %s."),*(( *menuToBuild.Get() )[i].GetText().ToString()));
	}
}
