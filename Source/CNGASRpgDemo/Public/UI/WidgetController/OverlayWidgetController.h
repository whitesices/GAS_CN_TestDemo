// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/CNWidgetController.h"
#include "AbilitySystemComponent.h"
#include "OverlayWidgetController.generated.h"

/**
 * 
 */
//进行一个向下处理的广播
//声明一个多播委托
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeValueChangeSignature ,float ,NewValue);

UCLASS()
class CNGASRPGDEMO_API UOverlayWidgetController : public UCNWidgetController
{
	GENERATED_BODY()


public:
	//重写在基类中绑定 广播的方法

	virtual void BroadcastInitialValues() override;

	virtual void BindCallbackToDepencies() override;

public:
	//声明自定义的多播类型 变量
	UPROPERTY( BlueprintAssignable , Category = "GAS|Attributes")
	FOnAttributeValueChangeSignature OnHealthChanged;

	UPROPERTY( BlueprintAssignable , Category = "GAS|Attributes")
	FOnAttributeValueChangeSignature OnMaxHealthChanged;

	UPROPERTY( BlueprintAssignable , Category = "GAS|Attributes")
	FOnAttributeValueChangeSignature OnManaChanged;

	UPROPERTY( BlueprintAssignable , Category = "GAS|Attributes")
	FOnAttributeValueChangeSignature OnMaxManaChanged;

protected:
	//声明AddUObject需要绑定的方法, 注意数据类型为FOnAttributeChangeData ， 因为GetGameplayAttributeValueChangeDelegate 传播的数据类型是FOnAttributeChangeData
	void OnHealthChange(const FOnAttributeChangeData& Data);

	void OnMaxHealthChange(const FOnAttributeChangeData& Data);
	
};
