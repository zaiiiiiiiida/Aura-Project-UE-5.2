// All the rights reserved.


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include <Windows/DirectX/include/d3d12.h>

#include "AbilitySystem/AuraAttributeSet.h"
#include "AuraGameplayTags.h"


void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);

	check(AttributeInfo)
for(auto& Pair: AS->TagsToAttributes)
{
	FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(Pair.Key);
	Info.AttributeValue =  Pair.Value().GetNumericValue(AS);
	AttributeInfoDelegate.Broadcast(Info);

}
}

