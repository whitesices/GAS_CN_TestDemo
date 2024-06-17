// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CNUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class CNGASRPGDEMO_API UCNUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	//自定义一个设置WidgetController的方法
	UFUNCTION( BlueprintCallable , Category="CNWdiget")
	void SetWidgetController(UObject* InWidgetController);

	//声明一个Controller变量
	UPROPERTY( BlueprintReadOnly )
	TObjectPtr<UObject> WidgetController;

protected:
	//声明一个WidgetController函数
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
	
};
