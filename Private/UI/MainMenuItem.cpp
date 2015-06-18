// © 2015 Mark Vatsel

#include "Manipulators_01.h"
#include "Public/UI/MainMenu/MainMenuItem.h"


FMainMenuItem::FMainMenuItem(FText _text, MainMenuItem type, bool _inactive)
{
	menuType = type;
	text = _text;
	inactive = _inactive;
}
