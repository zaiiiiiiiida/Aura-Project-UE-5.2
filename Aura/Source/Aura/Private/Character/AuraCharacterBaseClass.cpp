// All the rights reserved.


#include "Character/AuraCharacterBaseClass.h"
#include  "AbilitySystemComponent.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"


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

FVector AAuraCharacterBaseClass::GetCombatSocketLocation()
{
	check(Weapon)
	return Weapon->GetSocketLocation(WeaponTipSocketName);
}

void AAuraCharacterBaseClass::InitAbilityActorInfo()
{
}

void AAuraCharacterBaseClass::ApplyEffectToSelf(TSubclassOf<UGameplayEffect>GameplayEffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const  FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(),GetAbilitySystemComponent());
}

void AAuraCharacterBaseClass::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultVitalAttributes, 1.f);
}

void AAuraCharacterBaseClass::AddCharacterAbilities()
{
	UAuraAbilitySystemComponent* AuraASC = CastChecked<UAuraAbilitySystemComponent>(AbilitySystemComponent);
	if(!HasAuthority()) return;

	AuraASC->AddCharacterAbilities(StartUpAbilities);
}




