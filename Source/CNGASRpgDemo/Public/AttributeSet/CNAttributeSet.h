// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"

#include "CNAttributeSet.generated.h"

/**
 * 
 */

//该宏定义的作用便是不用再去手写get set 方法 来节省代码量
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)





UCLASS()
class CNGASRPGDEMO_API UCNAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	//定义一个构造函数
	UCNAttributeSet();


	virtual void GetLifetimeReplicatedProps( TArray<FLifetimeProperty>& OutLifetimeProps ) const override;

	//重载PreAttributeChange( const FGameplayAttribute& Attribute , float& Newvalue）
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	//修改BaseValue
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;


	//建立一个Tag映射方便值的查找对应的函数指针获取对应的值
	TMap< FGameplayTag, FGameplayAttribute(*)() > TagToAttributes;



public:

	//必要属性
	//声明一个健康属性变量
	UPROPERTY( BlueprintReadOnly , ReplicatedUsing = OnRep_Health )
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, Health)
	//声明网络复制所需要实现的自定义的方法
	UFUNCTION()
	void OnRep_Health( const FGameplayAttributeData& OldHealth );


	//声明一个mana即魔法量属性的变量
	UPROPERTY( BlueprintReadOnly , ReplicatedUsing = OnRep_Mana )
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, Mana)

	//声明网络复制所需要实现的Mana自定义方法
	UFUNCTION()
	void OnRep_Mana( const FGameplayAttributeData& OldMana );


	//主要属性
	UPROPERTY( BlueprintReadOnly , ReplicatedUsing = OnRep_Strength )
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS( UCNAttributeSet, Strength )

	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength);
	/*------*/
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence)
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, Intelligence)

	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence);
	/*------*/
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Resiliense)
	FGameplayAttributeData Resiliense;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, Resiliense)

	UFUNCTION()
	void OnRep_Resiliense(const FGameplayAttributeData& OldResiliense);
	/*------*/
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Vigor)
	FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, Vigor)

	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor);

	//次要属性
	//减少受到的伤害，提高阻挡几率
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor , Category = "Secondary_Attribute")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, Armor)

	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor);

	//忽略敌方护甲的百分比，增加暴击几率
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ArmorPenetration, Category = "Secondary_Attribute")
	FGameplayAttributeData ArmorPenetration;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, ArmorPenetration)

	UFUNCTION()
	void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration);

	//将传入伤害减半的概率
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BlockChance, Category = "Secondary_Attribute")
	FGameplayAttributeData BlockChance;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, BlockChance)

	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance);

	//获得暴击(双倍)伤害几率
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitChance, Category = "Secondary_Attribute")
	FGameplayAttributeData CriticalHitChance;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, CriticalHitChance)

	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance);

	//获得暴击时增加的额外伤害
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitDamage, Category = "Secondary_Attribute")
	FGameplayAttributeData CriticalHitDamage;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, CriticalHitDamage)

	UFUNCTION()
	void OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage);

	//降低攻击敌人的暴击几率
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitResistance, Category = "Secondary_Attribute")
	FGameplayAttributeData CriticalHitResistance;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, CriticalHitResistance)

	UFUNCTION()
	void OnRep_CriticalHitResistance(const FGameplayAttributeData& OldCriticalHitResistance);

	//每秒再生的生命值
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthRegeneration, Category = "Secondary_Attribute")
	FGameplayAttributeData HealthRegeneration;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, HealthRegeneration)

	UFUNCTION()
	void OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration);

	//每秒再生的魔法值
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaRegeneration, Category = "Secondary_Attribute")
	FGameplayAttributeData ManaRegeneration;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, ManaRegeneration)

	UFUNCTION()
	void OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration);

	//声明一个最大健康属性变量
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, MaxHealth)

	//声明网络复制所需要实现的最大健康属性所要实现的方法
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldAMaxHealth);

	// 声明一个MaxMana变量的魔法属性
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana)
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, MaxMana)

	//声明网络复制所需要实现的MaxMana自定义的方法
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana);


};
