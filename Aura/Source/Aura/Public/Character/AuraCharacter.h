// All the rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBaseClass.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBaseClass
{
	GENERATED_BODY()

public:
	AAuraCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:

	virtual void InitAbilityActorInfo() override;
	
};
