// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/CNWidgetController.h"
#include "AbilitySystemComponent.h"
#include "OverlayWidgetController.generated.h"

/**
 * 
 */
//����һ�����´���Ĺ㲥
//����һ���ಥί��
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeValueChangeSignature ,float ,NewValue);

UCLASS()
class CNGASRPGDEMO_API UOverlayWidgetController : public UCNWidgetController
{
	GENERATED_BODY()


public:
	//��д�ڻ����а� �㲥�ķ���

	virtual void BroadcastInitialValues() override;

	virtual void BindCallbackToDepencies() override;

public:
	//�����Զ���Ķಥ���� ����
	UPROPERTY( BlueprintAssignable , Category = "GAS|Attributes")
	FOnAttributeValueChangeSignature OnHealthChanged;

	UPROPERTY( BlueprintAssignable , Category = "GAS|Attributes")
	FOnAttributeValueChangeSignature OnMaxHealthChanged;

	UPROPERTY( BlueprintAssignable , Category = "GAS|Attributes")
	FOnAttributeValueChangeSignature OnManaChanged;

	UPROPERTY( BlueprintAssignable , Category = "GAS|Attributes")
	FOnAttributeValueChangeSignature OnMaxManaChanged;

protected:
	//����AddUObject��Ҫ�󶨵ķ���, ע����������ΪFOnAttributeChangeData �� ��ΪGetGameplayAttributeValueChangeDelegate ����������������FOnAttributeChangeData
	void OnHealthChange(const FOnAttributeChangeData& Data);

	void OnMaxHealthChange(const FOnAttributeChangeData& Data);
	
};
