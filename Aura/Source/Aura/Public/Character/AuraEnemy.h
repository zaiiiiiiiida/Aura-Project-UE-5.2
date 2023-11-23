// All the rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBaseClass.h"
#include "Interaction/EnemyInterface.h"
#include "UI/WidgetController/OverlayWidgetControllerClass.h"
#include "AbilitySystem/Data/CharacterClassInfo.h"
#include "AuraEnemy.generated.h"

class UWidgetComponent;
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

	//~start CombatInterface
    virtual  int32 GetPlayerLevel() override;
	
	//~end CombatInterface

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxHealthChanged;

	void OnHitReactChanged(FGameplayTag CallbackTag, int32 NewCount);

	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	bool bHitReacting = false;

	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	float BaseWalkSpeed = 250.f;
	
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	virtual void InitializeDefaultAttributes() const override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category= "CharacterClassDefaults")
	int32 Level = 1;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "Character Class Defaults")
	ECharacterClass CharacterClass = ECharacterClass::Warrior;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;
};
