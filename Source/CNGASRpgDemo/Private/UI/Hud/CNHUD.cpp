// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Hud/CNHUD.h"
#include "Blueprint/UserWidget.h"
//需要引入自己定义的UserWidget
#include "UI/Widget/CNUserWidget.h"

//用InitWidget来替代在Beginplay里添加UI
void ACNHUD::InitWidget(APlayerController* pc, APlayerState* ps, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{

	//检查OverlayWidgetClass是否有效
	if (!OverlayWidgetClass)
	{
		return;
	}

	//检查OverlayWidgetClass是否有效
	if (!OverlayWidgetClass)
	{
		return;
	}
	//课程中使用的是Checkf但会报错 因此记录相应代码以作后续参考

	/*checkf(OverlayWidgetControllerClass, TEXT("当前OverlayWidgetController无效,请在HUD蓝图中设置"));
	checkf(OverlayWidgetClass, TEXT("当前OverlayWidgetClass无效,请在HUD蓝图中设置"));*/

	//声明CreateWidget方法 类似蓝图里的操作
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);

	//这下面的操作其实都是给OverlayWidget进行初始化方便之后Controller操作model层
	//给OverlayWidget进行赋值
	OverlayWidget = Cast<UCNUserWidget>(Widget);

	//在Hud中创建FWidgetControllerParams
	FWidgetControllerParams Params( pc, ps, ASC, AS );

	//创建一个OverlayWidgetController并将GetOverlayWidgetController结果传进去

	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(Params);
	//设置widgetController
	OverlayWidget->SetWidgetController( WidgetController );

	//在HUD中进行广播相应参数
	//将Controller层中的数据广播到View层
	OverlayWidgetController->BroadcastInitialValues();




	//将UI添加到屏幕上
	Widget->AddToViewport();
}



UOverlayWidgetController* ACNHUD::GetOverlayWidgetController(const FWidgetControllerParams& Params)
{
	if (OverlayWidgetController == nullptr)
	{
		//若OverlayWidgetController为空则重新给OverlayWidgetController赋值
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);

		//调用SetWidgetControllerParams方法并进行赋值
		OverlayWidgetController->SetWidgetControllerParams(Params);

		//获取OverWidgetController再进行绑定相应依赖
		OverlayWidgetController->BindCallbackToDepencies();
	}



	////声明CreateWidget方法 类似蓝图里的操作
	//UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);

	////将UI添加到屏幕上
	//Widget->AddToViewport();

	return OverlayWidgetController;
}

//void ACNHUD::BeginPlay()
//{
//	Super::BeginPlay();
//
//	//声明CreateWidget方法 类似蓝图里的操作
//	UUserWidget* Widget = CreateWidget<UUserWidget>( GetWorld() , OverlayWidgetClass );
//
//	//将UI添加到屏幕上
//	Widget->AddToViewport();
//
//}
