// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/CNGasRpgPlayerController.h"
//引入增强系统输入头文件
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

//class UEnhancedInputComponent;

void ACNGasRpgPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//这里使用check其实类似与使用ifelse 但要注意后面使用check会报错不要滥用check
	//检查RPGContext输入的值是否有效
	check(RpgContext);
	//与蓝图中加载增强输入子系统的方式一样
	UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer() );
	//将IMC加入增强输入子系统中
	EnhancedInputSubsystem->AddMappingContext(RpgContext , 0 );
	//显示光标的操作 ，其实也可以在蓝图中进行勾选操作
	bShowMouseCursor = true;

	//设置输入模式
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);


}

void ACNGasRpgPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//声明一个增强输入移动组件的变量
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>( InputComponent );
	EnhancedInputComponent->BindAction(RpgMoveAction , ETriggerEvent::Triggered , this , &ACNGasRpgPlayerController::Move);//可以用ThisClass进行平替



}

void ACNGasRpgPlayerController::Move(const FInputActionValue& InputActionValue)
{
	//获取X轴和Y轴两个方向的数据
	const FVector2d InputAxisVector = InputActionValue.Get<FVector2d>();

	const FRotator Rotation = GetControlRotation();

	const FRotator YawRotation(0.f , Rotation.Yaw , 0.f );

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);//X方向
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);//Y方向

	if (APawn* ControlledPawn = GetPawn())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}
