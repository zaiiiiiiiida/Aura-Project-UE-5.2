// All the rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBaseClass.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBaseClass, public IEnemyInterface
{
	GENERATED_BODY()
public:
	AAuraEnemy();
	//~start EnemyInterface
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	//~end EnemyInterface
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	
};
