// All the rights reserved.


#include "Character/AuraCharacterBaseClass.h"


AAuraCharacterBaseClass::AAuraCharacterBaseClass()
{
	PrimaryActorTick.bCanEverTick = false;
	Weapon=CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AAuraCharacterBaseClass::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAuraCharacterBaseClass::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraCharacterBaseClass::InitAbilityActorInfo()
{
}

