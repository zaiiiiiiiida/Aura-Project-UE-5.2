// All the rights reserved.


#include "Character/AuraCharacterBaseClass.h"
#include  "AbilitySystemComponent.h"


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

void AAuraCharacterBaseClass::InitializePrimaryAttributes()const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(DefaultPrimaryAttributes);
	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const  FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DefaultPrimaryAttributes, 1.f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(),GetAbilitySystemComponent());
}

