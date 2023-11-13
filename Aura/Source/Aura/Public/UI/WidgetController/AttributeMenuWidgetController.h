// All the rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/AuraWidgetControllerClass.h"
#include "AttributeMenuWidgetController.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAttributeMenuWidgetController : public UAuraWidgetControllerClass
{
	GENERATED_BODY()
public:
	virtual void BindCallbacksToDependencies() override;
	virtual void BroadcastInitialValues() override;
	
};
