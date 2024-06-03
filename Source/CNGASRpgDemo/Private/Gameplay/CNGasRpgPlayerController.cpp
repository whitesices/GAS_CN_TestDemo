// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/CNGasRpgPlayerController.h"
//引入增强系统输入头文件
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interface/EnemyInterface.h"

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

void ACNGasRpgPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	//在playerTick中去调用CursorTrace
	CursorTrace();
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

void ACNGasRpgPlayerController::CursorTrace()
{
	//声明一个变量来获取触及的效果
	FHitResult HitResult;

	GetHitResultUnderCursor(ECC_Visibility , false, HitResult);

	//若反馈结果为空则直接返回
	if( !HitResult.bBlockingHit ) return;
	LastActor = CurrentActor;
	//这里要注意类型的转换
	CurrentActor =HitResult.GetActor();
	/*
	 *1.currentactor为空 lastactor为空
	 *2.currentactor为空 lastactor不为空 
	 *3.currentactor为空 ， lastactor为空
	 * 4.两者都不为空
	 */


	/*if( !LastActor && !CurrentActor )
	{
		return;
	}
	else if( !LastActor && CurrentActor )
	{
		if( CurrentActor->Implements<IEnemyInterface>())
		{
			IEnemyInterface::Execute_HighLight(CurrentActor);
		}
	}
	else if (LastActor && !CurrentActor)
	{
		if (LastActor->Implements<IEnemyInterface>())
		{
			IEnemyInterface::Execute_UnHighLight(LastActor);
		}
	}
	else if (LastActor && CurrentActor)
	{
		if (LastActor->Implements<IEnemyInterface>())
		{
			IEnemyInterface::Execute_UnHighLight(LastActor);
		}

		if (CurrentActor->Implements<IEnemyInterface>())
		{
			IEnemyInterface::Execute_HighLight(CurrentActor);
		}

	}*/

	//当当前actor与之前都为空时则直接返回不继续进行接下来的操作

	if (!LastActor && !CurrentActor)
	{
		return;
	}
	
	//逻辑优化实则便是 当前Actor有效则执行高亮 ， 之前的Actor有效则执行不高亮

	if ( LastActor && LastActor->Implements<UEnemyInterface>() )
	{
		IEnemyInterface::Execute_UnHighLight(LastActor);
	}
	
	if ( CurrentActor && CurrentActor->Implements<UEnemyInterface>() )
	{
		IEnemyInterface::Execute_HighLight(CurrentActor);
	}

	
}
