// All the rights reserved.


#include "AbilitySystem/AuraAbilitySystemGlobals.h"

#include "AuraAbilityEffectTypes.h"

FGameplayEffectContext* UAuraAbilitySystemGlobals::AllocGameplayEffectContext() const
{
	return new FAuraGameplayEffectContext();
}