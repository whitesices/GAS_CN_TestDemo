// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/CNWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"


struct FCNAttributeInfo;
class UAttributeInfo;
//class FGameplayAttribute;

//新建一个委托
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam( FAttributeInfoSignature, const FCNAttributeInfo& , Info) ;

/**
 * 
 */
UCLASS( BlueprintType , Blueprintable )
class CNGASRPGDEMO_API UAttributeMenuWidgetController : public UCNWidgetController
{
	GENERATED_BODY()

public:
	//继承CNWidgetController中的绑定和广播的方法
	UFUNCTION( BlueprintCallable ) //blueprintable 蓝图可调用
	virtual void BroadcastInitialValues() override;

	virtual void BindCallbackToDepencies() override;


	//声明一个委托变量
	UPROPERTY( BlueprintAssignable , Category = "GAS|Attributes")
	FAttributeInfoSignature AttributeInfoDelegate;

	////此条注释是为了 解决git显示无修改的问题
	//void BroadCastAttributeInfoCN(const FGameplayTag& Gaemplay, FGameplayAttribute GameplayAttribute);
	
protected:

	//声明一个AttributeInfo的变量
	UPROPERTY( EditDefaultsOnly )
	TObjectPtr<UAttributeInfo>  AttributeInfo;

	////新声明一个广播AttributeInfo参数的方法
	//void BroadcastAttributeInfoByCN(const FGameplayTag& GameplayTag, FGameplayAttribute GameplayAttribute, UCNAttributeSet* AS);

	
};
