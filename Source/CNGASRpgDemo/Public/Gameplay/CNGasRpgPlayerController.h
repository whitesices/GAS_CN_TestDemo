// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "CNGasRpgPlayerController.generated.h"
//若UInputMappingContext未被识别则表明未引入头文件或者预加载相关选项
//#include "InputMappingContext.h"

class UInputMappingContext;
class UInputAction;
/**
 * 
 */
UCLASS()
class CNGASRPGDEMO_API ACNGasRpgPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	//在playercontroller方法中重载beginplay与移动输入组件方法
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

private:
	
	UPROPERTY( EditorAnywhere , Category = "Input" )
	TObjectPtr<UInputMappingContext> RpgContext;//这部门内容其实是吸入IMC

	UPROPERTY( EditorAnywhere ,Category = "Input")
	TObjectPtr<UInputAction> RpgMoveAction;//这部分是装入IA

	//自定义一个move方法在移动组件中进行调用
	void Move( const FInputActionValue& InputActionValue );
	
};
