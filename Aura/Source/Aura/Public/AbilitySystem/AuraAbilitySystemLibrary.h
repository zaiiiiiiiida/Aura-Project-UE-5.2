// All the rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AuraAbilitySystemLibrary.generated.h"

class UAttributeMenuWidgetController;
class UOverlayWidgetControllerClass;

/**
 * 
 */
UCLASS()
class AURA_API UAuraAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintPure, Category= "AuraAbilitySystemLibrary|WidgetConroller")
	static UOverlayWidgetControllerClass* GetOverlayWidgetController(const UObject* WorldContextObject);
	

	UFUNCTION(BlueprintPure, Category = "AuraAbilitySystemLibrary|WidgetConroller")
	static UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const UObject* WorldContextObject);
	
};
