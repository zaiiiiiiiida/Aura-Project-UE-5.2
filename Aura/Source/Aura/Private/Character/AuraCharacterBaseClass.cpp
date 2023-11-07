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

void AAuraCharacterBaseClass::ApplyEffectToSelf(TSubclassOf<UGameplayEffect>GameplayEffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const  FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(),GetAbilitySystemComponent());
}

void AAuraCharacterBaseClass::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultSecondaryPrimaryAttributes, 1.f);
}


