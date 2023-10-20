// All the rights reserved.


#include "UI/WidgetController/AuraWidgetControllerClass.h"

void UAuraWidgetControllerClass::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UAuraWidgetControllerClass::BroadcastInitialValues()
{
	
}

void UAuraWidgetControllerClass::BindCallbacksToDependencies()
{
	
}
