// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/CNWidgetController.h"
#include "AbilitySystemComponent.h"
#include "OverlayWidgetController.generated.h"

class UCNUserWidget;


USTRUCT( BlueprintType )
struct FUIWidgetRow : public FTableRowBase
{
	GENERATED_BODY()

	//声明GameplayTag
	UPROPERTY( EditAnywhere , BlueprintReadOnly )
	FGameplayTag MessageTag = FGameplayTag();

	//声明FText 文本变量信息
	UPROPERTY( EditAnywhere , BlueprintReadOnly )
	FText Message = FText();

	//声明自定的UCNUserWidget的类变量
	UPROPERTY( EditAnywhere , BlueprintReadOnly )
	TSubclassOf<UCNUserWidget> MessageWidget;


	//声明一个Texture2D的变量
	UPROPERTY( EditAnywhere , BlueprintReadOnly )
	UTexture2D* Image = nullptr;

};

/**
 * 
 */
//进行一个向下处理的广播
//声明一个多播委托
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeValueChangeSignature ,float ,NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMessageWidgetRowSignature , FUIWidgetRow, Row);

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

	//定义委托从DataTable读取的数据
	UPROPERTY( BlueprintAssignable , Category = "GAS|Message")
	FMessageWidgetRowSignature MessageWidgetRowDelegate;

protected:
	//声明AddUObject需要绑定的方法, 注意数据类型为FOnAttributeChangeData ， 因为GetGameplayAttributeValueChangeDelegate 传播的数据类型是FOnAttributeChangeData
	void OnHealthChange(const FOnAttributeChangeData& Data);

	void OnMaxHealthChange(const FOnAttributeChangeData& Data);

protected:
	//声明一个DataTable的变量
	UPROPERTY( EditDefaultsOnly , BlueprintReadOnly , Category = "Widget_Data")
	TObjectPtr<UDataTable> MessageWidgetDataTable;

	//声明存储游戏tag的变量
	template< typename T >
	T* GetDataTableRowByTag( UDataTable* DataTable , const FGameplayTag& Tag);
	
};

template<typename T>
inline T* UOverlayWidgetController::GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag)
{
	return DataTable->FindRow<T>( Tag.GetTagName(), TEXT("") );
}
