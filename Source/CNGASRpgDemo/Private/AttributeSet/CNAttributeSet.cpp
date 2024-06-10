// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSet/CNAttributeSet.h"
#include "AbilitySystemComponent.h"
//引入虚幻联网头文件
#include "Net/UnrealNetwork.h"

UCNAttributeSet::UCNAttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(150.f);
	InitMana(50.f);
	InitMaxMana(100.f);
}

void UCNAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//通知当前自定义属性的状态
	DOREPLIFETIME_CONDITION_NOTIFY(UCNAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCNAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCNAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCNAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);

}

void UCNAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCNAttributeSet, Health, OldHealth);
}

void UCNAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldAMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCNAttributeSet, MaxHealth, OldAMaxHealth);
}

void UCNAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCNAttributeSet, Mana, OldMana);
}

void UCNAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCNAttributeSet, MaxMana, OldMaxMana);
}
