// All the rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterClassInfo.generated.h"

class UGameplayAbility;
class UGameplayEffect;

UENUM(BlueprintType)
enum class ECharacterClass : uint8
{
	Elementalist,
	Warrior,
	Ranger
};

USTRUCT()
struct FCharacterClassDefaultInfo
{
	GENERATED_BODY()


	UPROPERTY(EditDefaultsOnly, Category="ClassDefaults")
	TSubclassOf<UGameplayEffect>PrimaryAttributes;
	
};
/**
 * 
 */
UCLASS()
class AURA_API UCharacterClassInfo : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, Category="Character Class Defaults")
	TMap<ECharacterClass,FCharacterClassDefaultInfo>CharacterClassInformation;
	
	
	UPROPERTY(EditDefaultsOnly, Category="Common Class Defaults")
	TSubclassOf<UGameplayEffect>SecondaryAttributes;

	UPROPERTY(EditDefaultsOnly, Category="Common Class Defaults")
	TSubclassOf<UGameplayEffect>VitalAttributes;

	FCharacterClassDefaultInfo GetClassDefaultInfo(ECharacterClass CharacterClass);


	UPROPERTY(EditDefaultsOnly,Category="Common Class Defaults")
	TArray<TSubclassOf<UGameplayAbility>> CommonAbilities;
	
};
