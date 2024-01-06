// All the rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBaseClass.h"
#include "Interaction/EnemyInterface.h"
#include "UI/WidgetController/OverlayWidgetControllerClass.h"
#include "AbilitySystem/Data/CharacterClassInfo.h"
#include "AuraEnemy.generated.h"

class UWidgetComponent;
class UBehaviorTree;
class AAuraAIController;
/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBaseClass, public IEnemyInterface
{
	GENERATED_BODY()
public:
	AAuraEnemy();
	
	virtual void PossessedBy(AController* NewController) override;
	
	//~start EnemyInterface
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	//~end EnemyInterface

	//~start CombatInterface
    virtual  int32 GetPlayerLevel() override;
	
	//~end CombatInterface
	virtual void Die() override;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxHealthChanged;

	void OnHitReactChanged(FGameplayTag CallbackTag, int32 NewCount);

	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	bool bHitReacting = false;

	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	float BaseWalkSpeed = 250.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat")
	float LifeSpan = 5;
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

	UPROPERTY(EditAnywhere, Category = "AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY()
	TObjectPtr<AAuraAIController> AuraAIController;

	
};
