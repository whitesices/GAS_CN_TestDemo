// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * 
 */
struct FAuraGameplayTags
{
public:

	//定义GameplayTag的get方法
	static const FAuraGameplayTags& Get()
	{
		return GameplayTags;
	}

	//初始化GameplayTag的方法
	static void InitializeNativeGameplayTags();

	//定义GameplayTag变量
	//主要属性
	FGameplayTag Attribute_Primary_Strength;
	FGameplayTag Attribute_Primary_Intelligence;
	FGameplayTag Attribute_Primary_Resilience;
	FGameplayTag Attribute_Primary_Vigor;

	//次要属性
	FGameplayTag Attribute_Secondary_Armor;
	FGameplayTag Attribute_Secondary_ArmorPenetration;
	FGameplayTag Attribute_Secondary_BlockChance;
	FGameplayTag Attribute_Secondary_CriticalHitChance;
	FGameplayTag Attribute_Secondary_CriticalHitDamage;
	FGameplayTag Attribute_Secondary_CriticalHitResistance;
	FGameplayTag Attribute_Secondary_HealthRegeneration;
	FGameplayTag Attribute_Secondary_ManaRegeneration;
	FGameplayTag Attribute_Secondary_MaxHealth;
	FGameplayTag Attribute_Secondary_MaxMana;




private:
	static FAuraGameplayTags GameplayTags;
};





//class CNGASRPGDEMO_API AuraGameplayTags
//{
//public:
//	AuraGameplayTags();
//	~AuraGameplayTags();
//};
