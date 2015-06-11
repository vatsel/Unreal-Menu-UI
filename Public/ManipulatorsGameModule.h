//© 2015 Mark Vatsel

#include "Manipulators_01.h"

/**
* Run as default game module to load assets and un/register style sets. Otherwise Hot Reload will throw assertion errors.
*/
class FManipulatorsGameModule : public FDefaultGameModuleImpl
{
	void StartupModule() override;
	void ShutdownModule() override;
};
