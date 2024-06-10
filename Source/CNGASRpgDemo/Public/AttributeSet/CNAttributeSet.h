// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CNAttributeSet.generated.h"

/**
 * 
 */

//�ú궨������ñ��ǲ�����ȥ��дget set ���� ����ʡ������
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
	//����һ�����캯��
	UCNAttributeSet();


	virtual void GetLifetimeReplicatedProps( TArray<FLifetimeProperty>& OutLifetimeProps ) const override;

	//����һ���������Ա���
	UPROPERTY( BlueprintReadOnly , ReplicatedUsing = OnRep_Health )
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, Health)
	//�������縴������Ҫʵ�ֵ��Զ���ķ���
	UFUNCTION()
	void OnRep_Health( const FGameplayAttributeData& OldHealth );

	//����һ����󽡿����Ա���
	UPROPERTY( BlueprintReadOnly , ReplicatedUsing=OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, MaxHealth)

	//�������縴������Ҫʵ�ֵ���󽡿�������Ҫʵ�ֵķ���
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldAMaxHealth);

	//����һ��mana��ħ�������Եı���
	UPROPERTY( BlueprintReadOnly , ReplicatedUsing = OnRep_Mana )
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, Mana)

	//�������縴������Ҫʵ�ֵ�Mana�Զ��巽��
	UFUNCTION()
	void OnRep_Mana( const FGameplayAttributeData& OldMana );

	//����һ��MaxMana������ħ������
	UPROPERTY(BlueprintReadOnly , ReplicatedUsing = OnRep_MaxMana )
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UCNAttributeSet, MaxMana)

	//�������縴������Ҫʵ�ֵ�MaxMana�Զ���ķ���
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana);
};
