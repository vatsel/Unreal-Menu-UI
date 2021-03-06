// © 2015 Mark Vatsel

#pragma once
#include "GameFramework/HUD.h"
#include "Public/UI/MainMenu/MainMenuWidget.h"
#include "Public/UI/MainMenu/MainMenuItem.h"
#include "Public/EnumTypes.h"
#include "MainMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class MANIPULATORS_01_API AMainMenuHUD : public AHUD
{
	GENERATED_UCLASS_BODY()
	TSharedPtr<class SMainMenuWidget> mainMenuWidget;	
	TSharedPtr<TArray<FMainMenuItem>> menu;
	
public:
	TSharedPtr<TArray<class FMainMenuItem>> menuContainer;

	/** May be null! */
	TSharedPtr<TArray<FMainMenuItem>> GetMenu() { return menu; }

	virtual void PostInitializeComponents() override;
	void RebuildWidgets(bool bHotReload = false);
	void LoadMainLevel();
	void ExecuteQuit();

	/** Adds newly created FMainMenuItem data container to a menu. Creates new menu if pointer invalid.*/
	FMainMenuItem* AddMenuItem(TSharedPtr<TArray<class FMainMenuItem>> &appendToMenu, MainMenuItem type, FText buttonText, bool inactive=false);
};