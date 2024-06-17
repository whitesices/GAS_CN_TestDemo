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




public:
	//声明一个健康属性变量
	UPROPERTY( BlueprintReadOnly , ReplicatedUsing = OnRep_Health )
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, Health)
	//声明网络复制所需要实现的自定义的方法
	UFUNCTION()
	void OnRep_Health( const FGameplayAttributeData& OldHealth );

	//声明一个最大健康属性变量
	UPROPERTY( BlueprintReadOnly , ReplicatedUsing=OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, MaxHealth)

	//声明网络复制所需要实现的最大健康属性所要实现的方法
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldAMaxHealth);

	//声明一个mana即魔法量属性的变量
	UPROPERTY( BlueprintReadOnly , ReplicatedUsing = OnRep_Mana )
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, Mana)

	//声明网络复制所需要实现的Mana自定义方法
	UFUNCTION()
	void OnRep_Mana( const FGameplayAttributeData& OldMana );

	//声明一个MaxMana变量的魔法属性
	UPROPERTY(BlueprintReadOnly , ReplicatedUsing = OnRep_MaxMana )
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, MaxMana)

	//声明网络复制所需要实现的MaxMana自定义的方法
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana);
};
