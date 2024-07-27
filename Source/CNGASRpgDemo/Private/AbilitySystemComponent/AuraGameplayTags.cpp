// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystemComponent/AuraGameplayTags.h"

//引入GameplayTagManager
#include  "GameplayTagsManager.h"

//AuraGameplayTags::AuraGameplayTags()
//{
//}
//
//AuraGameplayTags::~AuraGameplayTags()
//{
//}

//初始化定义GameplayTag变量
FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	//主要属性
	//进行GameplayTag初始化
	GameplayTags.Attribute_Primary_Strength = UGameplayTagsManager::Get()
		.AddNativeGameplayTag(FName("Attribute.Primary.Strength"), FString( TEXT("增加物理伤害") ) );

	GameplayTags.Attribute_Primary_Intelligence = UGameplayTagsManager::Get()
		.AddNativeGameplayTag(FName("Attribute.Primary.Intelligence"), FString(TEXT("增加精神力")));

	GameplayTags.Attribute_Primary_Resilience = UGameplayTagsManager::Get()
		.AddNativeGameplayTag(FName("Attribute.Primary.Resilience"), FString(TEXT("增加护甲和护甲穿透")));

	GameplayTags.Attribute_Primary_Vigor = UGameplayTagsManager::Get()
		.AddNativeGameplayTag(FName("Attribute.Primary.Vigor"), FString(TEXT("增加生命值")));

	//次要属性
	//进行相应的GameplayTag的初始化
	GameplayTags.Attribute_Secondary_Armor = UGameplayTagsManager::Get()
		.AddNativeGameplayTag(FName("Attribute.Secondary.Armor"), FString(TEXT("减少受到的伤害，提高闪避(格挡几率)")));

	GameplayTags.Attribute_Secondary_ArmorPenetration = UGameplayTagsManager::Get()
		.AddNativeGameplayTag( FName("Attribute.Secondary.ArmorPenetration") , FString( TEXT("忽略敌方护甲百分比，增加暴击率")));

	GameplayTags.Attribute_Secondary_BlockChance = UGameplayTagsManager::Get()
		.AddNativeGameplayTag(FName("Attribute.Secondary.BlockChance"), FString(TEXT("对敌方伤害减半")));

	GameplayTags.Attribute_Secondary_CriticalHitChance = UGameplayTagsManager::Get()
		.AddNativeGameplayTag(FName("Attribute.Secondary.CriticalHitChance"), FString(TEXT("获得暴击双倍伤害")));

	GameplayTags.Attribute_Secondary_CriticalHitDamage = UGameplayTagsManager::Get()
		.AddNativeGameplayTag(FName("Attribute.Secondary.CriticalHitDamage"), FString(TEXT("获得暴击时增加的额外伤害")));

	GameplayTags.Attribute_Secondary_CriticalHitResistance = UGameplayTagsManager::Get()
		.AddNativeGameplayTag(FName("Attribute.Secondary.CriticalHitResistance"), FString( TEXT("降低攻击敌人的暴击几率") ) );

	GameplayTags.Attribute_Secondary_HealthRegeneration = UGameplayTagsManager::Get()
		.AddNativeGameplayTag(FName("Attribute.Secondary.HealthRegeneration"), FString(TEXT("每秒再生的生命值") ) );

	GameplayTags.Attribute_Secondary_ManaRegeneration = UGameplayTagsManager::Get()
		.AddNativeGameplayTag(FName("Attribute.Secondary.ManaRegeneration") , FString(TEXT("每秒再生的魔法值") ) );

	GameplayTags.Attribute_Secondary_MaxHealth = UGameplayTagsManager::Get()
		.AddNativeGameplayTag(FName("Attribute.Secondary.MaxHealth"), FString(TEXT("最大生命值")));

	GameplayTags.Attribute_Secondary_MaxMana = UGameplayTagsManager::Get()
		.AddNativeGameplayTag(FName("Attribute.Secondary.MaxMana") , FString(TEXT("最大魔法值") ) );
}
