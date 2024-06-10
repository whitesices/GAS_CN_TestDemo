// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "CNHUD.generated.h"

class UCNUserWidget;

//添加前置声明
class UAbilitySystemComponent;
class UAttributeSet;

/**
 * 
 */
UCLASS()
class CNGASRPGDEMO_API ACNHUD : public AHUD
{
	GENERATED_BODY()

public:
	//声明一个新的变量
	UPROPERTY()
	TObjectPtr< UCNUserWidget > OverlayWidget;

	//新建一个自定义初始化Widget函数
	void InitWidget(APlayerController* pc, APlayerState* ps, UAbilitySystemComponent* ASC, UAttributeSet* AS);

	//初始化OverlayWidgetController
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& Params);



protected:
	/*virtual void BeginPlay() override;*/

private:

	//声明一个UserWidget私有变量
	UPROPERTY(EditAnywhere)
	TSubclassOf<UCNUserWidget> OverlayWidgetClass;

	//声明一个OverlayWidgetController 变量
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	//声明OverlayWidgetController类
	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	
};
