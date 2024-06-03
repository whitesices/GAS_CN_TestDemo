// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
//#include "Interface/EnemyInterface.h"
#include "CNGasRpgPlayerController.generated.h"
//若UInputMappingContext未被识别则表明未引入头文件或者预加载相关选项
//#include "InputMappingContext.h"

class UInputMappingContext;
class UInputAction;
class IEnemyInterface;
/**
 * 
 */
UCLASS()
class CNGASRPGDEMO_API ACNGasRpgPlayerController : public APlayerController /*, public IEnemyInterface*/
{
	GENERATED_BODY()

protected:
	//在playercontroller方法中重载beginplay与移动输入组件方法
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	virtual void PlayerTick(float DeltaTime) override;

private:
	
	UPROPERTY( EditAnywhere , Category = "Input" )
	TObjectPtr<UInputMappingContext> RpgContext;//这部门内容其实是吸入IMC

	UPROPERTY( EditAnywhere ,Category = "Input")
	TObjectPtr<UInputAction> RpgMoveAction;//这部分是装入IA

	//自定义一个move方法在移动组件中进行调用
	void Move( const FInputActionValue& InputActionValue );
	
	//自定义一个Cursor函数
	void CursorTrace();

	//声明两个变量来存储上一个变量和当前变量
	AActor* LastActor;
	AActor* CurrentActor;


	
};
