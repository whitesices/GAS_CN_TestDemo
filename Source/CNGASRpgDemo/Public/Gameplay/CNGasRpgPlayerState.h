// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "CNGasRpgPlayerState.generated.h"


//引入相应的类
class UAbilitySystemComponent;
class UAttributeSet;

/**
 * 
 */
UCLASS()
class CNGASRPGDEMO_API ACNGasRpgPlayerState : public APlayerState , public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	ACNGasRpgPlayerState();

	//重载获取系统组件的方法
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	//定义一个获取技能属性的方法
	UAttributeSet* GetAttributeSet() const
	{
		return CNAttributeSet;
	}
	//声明一个技能系统组件变量
	UPROPERTY( VisibleAnywhere , Category = "CNAbilitySystemComponent")
	TObjectPtr<UAbilitySystemComponent> CNAbilitySystemComponent;

	//声明一个技能属性变量
	UPROPERTY( EditAnywhere , Category = "CNAttributeSet")
	TObjectPtr<UAttributeSet> CNAttributeSet;
	
};
