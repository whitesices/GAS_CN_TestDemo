// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Hud/CNHUD.h"
#include "Blueprint/UserWidget.h"
//��Ҫ�����Լ������UserWidget
#include "UI/Widget/CNUserWidget.h"

//��InitWidget�������Beginplay�����UI
void ACNHUD::InitWidget(APlayerController* pc, APlayerState* ps, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{

	//���OverlayWidgetClass�Ƿ���Ч
	if (!OverlayWidgetClass)
	{
		return;
	}

	//���OverlayWidgetClass�Ƿ���Ч
	if (!OverlayWidgetClass)
	{
		return;
	}
	//�γ���ʹ�õ���Checkf���ᱨ�� ��˼�¼��Ӧ�������������ο�

	/*checkf(OverlayWidgetControllerClass, TEXT("��ǰOverlayWidgetController��Ч,����HUD��ͼ������"));
	checkf(OverlayWidgetClass, TEXT("��ǰOverlayWidgetClass��Ч,����HUD��ͼ������"));*/

	//����CreateWidget���� ������ͼ��Ĳ���
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);

	//������Ĳ�����ʵ���Ǹ�OverlayWidget���г�ʼ������֮��Controller����model��
	//��OverlayWidget���и�ֵ
	OverlayWidget = Cast<UCNUserWidget>(Widget);

	//��Hud�д���FWidgetControllerParams
	FWidgetControllerParams Params( pc, ps, ASC, AS );

	//����һ��OverlayWidgetController����GetOverlayWidgetController�������ȥ

	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(Params);
	//����widgetController
	OverlayWidget->SetWidgetController( WidgetController );

	//��HUD�н��й㲥��Ӧ����
	//��Controller���е����ݹ㲥��View��
	OverlayWidgetController->BroadcastInitialValues();




	//��UI��ӵ���Ļ��
	Widget->AddToViewport();
}



UOverlayWidgetController* ACNHUD::GetOverlayWidgetController(const FWidgetControllerParams& Params)
{
	if (OverlayWidgetController == nullptr)
	{
		//��OverlayWidgetControllerΪ�������¸�OverlayWidgetController��ֵ
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);

		//����SetWidgetControllerParams���������и�ֵ
		OverlayWidgetController->SetWidgetControllerParams(Params);

		//��ȡOverWidgetController�ٽ��а���Ӧ����
		OverlayWidgetController->BindCallbackToDepencies();
	}



	////����CreateWidget���� ������ͼ��Ĳ���
	//UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);

	////��UI��ӵ���Ļ��
	//Widget->AddToViewport();

	return OverlayWidgetController;
}

//void ACNHUD::BeginPlay()
//{
//	Super::BeginPlay();
//
//	//����CreateWidget���� ������ͼ��Ĳ���
//	UUserWidget* Widget = CreateWidget<UUserWidget>( GetWorld() , OverlayWidgetClass );
//
//	//��UI��ӵ���Ļ��
//	Widget->AddToViewport();
//
//}
