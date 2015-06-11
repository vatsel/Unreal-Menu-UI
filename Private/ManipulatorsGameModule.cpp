//© 2015 Mark Vatsel


#include "Manipulators_01.h"
#include "Public/ManipulatorsGameModule.h"
#include "Public/UI/ManipulatorsStyle.h"



void FManipulatorsGameModule::StartupModule()
{
	//Hot reload hack, common for extending Slate functionailty
	FSlateStyleRegistry::UnRegisterSlateStyle(FManipulatorsStyle::styleSetName);
	FManipulatorsStyle::Initialize();
}

	
void FManipulatorsGameModule::ShutdownModule()
{
	FManipulatorsStyle::Shutdown();	
}

