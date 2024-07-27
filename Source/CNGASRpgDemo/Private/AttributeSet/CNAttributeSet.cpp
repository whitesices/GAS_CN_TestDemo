// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSet/CNAttributeSet.h"
#include "AbilitySystemComponent.h"
//引入虚幻联网头文件
#include "Net/UnrealNetwork.h"

UCNAttributeSet::UCNAttributeSet()
{
	InitHealth(100.f);
	/*InitMaxHealth(150.f);*/
	InitMana(50.f);
	/*InitMaxMana(100.f);*/
}

void UCNAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//通知当前自定义属性的状态
	DOREPLIFETIME_CONDITION_NOTIFY(UCNAttributeSet, Health, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UCNAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	

	//通知主要属性
	DOREPLIFETIME_CONDITION_NOTIFY(UCNAttributeSet, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCNAttributeSet, Intelligence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCNAttributeSet, Resiliense, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCNAttributeSet, Vigor, COND_None, REPNOTIFY_Always);

	//通知次要属性
	DOREPLIFETIME_CONDITION_NOTIFY(UCNAttributeSet, Armor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCNAttributeSet, ArmorPenetration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCNAttributeSet, BlockChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCNAttributeSet, CriticalHitChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCNAttributeSet, CriticalHitDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCNAttributeSet, CriticalHitResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCNAttributeSet, HealthRegeneration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCNAttributeSet, ManaRegeneration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCNAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
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

void UCNAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCNAttributeSet, Strength, OldStrength);
}

void UCNAttributeSet::OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCNAttributeSet, Intelligence, OldIntelligence);
}

void UCNAttributeSet::OnRep_Resiliense(const FGameplayAttributeData& OldResiliense)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCNAttributeSet, Resiliense, OldResiliense);
}

void UCNAttributeSet::OnRep_Vigor(const FGameplayAttributeData& OldVigor)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCNAttributeSet, Vigor, OldVigor);
}

void UCNAttributeSet::OnRep_Armor(const FGameplayAttributeData& OldArmor)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCNAttributeSet, Armor, OldArmor);
}

void UCNAttributeSet::OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCNAttributeSet, ArmorPenetration, OldArmorPenetration);
}

void UCNAttributeSet::OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCNAttributeSet, BlockChance, OldBlockChance);
}

void UCNAttributeSet::OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCNAttributeSet, CriticalHitChance, OldCriticalHitChance);
}

void UCNAttributeSet::OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCNAttributeSet, CriticalHitDamage, OldCriticalHitDamage);
}

void UCNAttributeSet::OnRep_CriticalHitResistance(const FGameplayAttributeData& OldCriticalHitResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCNAttributeSet, CriticalHitResistance, OldCriticalHitResistance);
}

void UCNAttributeSet::OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCNAttributeSet, HealthRegeneration, OldHealthRegeneration);
}

void UCNAttributeSet::OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCNAttributeSet, ManaRegeneration, OldManaRegeneration);
}
