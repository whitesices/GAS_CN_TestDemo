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

//重载Attribute预改变
void UCNAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	//判断获取的值是否大于最大值
	if (Attribute == GetHealthAttribute())
	{
		//获取最大生命值
		NewValue = FMath::Clamp( NewValue, 0.f,GetMaxHealth() );
	}

	if (Attribute == GetManaAttribute())
	{
		//获取最大魔法值
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana()); 
	}


}

//修改BaseValue
void UCNAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	//设置最大生命值
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		//对基础值的一个前置
		SetHealth( FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()) );
	}

	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana( FMath::Clamp(GetMana(), 0.f, GetMaxMana()));
	}
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
