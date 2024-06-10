// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CNWidgetController.generated.h"

/**
 * 
 */
class UAbilitySystemComponent;
class UAttributeSet;


//新定义一个U 结构体
USTRUCT( BlueprintType )
struct FWidgetControllerParams
{
	GENERATED_BODY()

	//声明一个无参构造函数
	FWidgetControllerParams(){}
	//声明一个有参构造函数
	FWidgetControllerParams( APlayerController* PC , APlayerState* PS , UAbilitySystemComponent* ASC , UAttributeSet* AS):PlayerController(PC), PlayerState(PS), AbilitySystemComponent(ASC), AttributeSet(AS)
	{}
	//记住这里需要加Public来公开函数
public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere , Category = "WidgetController")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere , Category = "WidgetController")
	TObjectPtr<APlayerState> PlayerState = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere ,Category = "WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet = nullptr;

};


//使用Blueprintable ：可蓝图化
UCLASS( Blueprintable )
class CNGASRPGDEMO_API UCNWidgetController : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION( BlueprintCallable )
	void SetWidgetControllerParams(const FWidgetControllerParams& WCParams);

protected:

	//新声明一个PlayerController属性
	UPROPERTY( BlueprintReadOnly , Category = "WidgetController")
	TObjectPtr<APlayerController> PlayerController;

	//声明一个PlayerSate的变量
	UPROPERTY( BlueprintReadOnly , Category = "WidgetController")
	TObjectPtr<APlayerState> PlayerState;

	//声明一个AbilitySystemComponent的变量
	UPROPERTY( BlueprintReadOnly , Category = "WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	//声明一个AttributeSet的变量
	UPROPERTY( BlueprintReadOnly , Category = "WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet;
	
};
