// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "CNHUD.generated.h"

class UCNUserWidget;

//���ǰ������
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
	//����һ���µı���
	UPROPERTY()
	TObjectPtr< UCNUserWidget > OverlayWidget;

	//�½�һ���Զ����ʼ��Widget����
	void InitWidget(APlayerController* pc, APlayerState* ps, UAbilitySystemComponent* ASC, UAttributeSet* AS);

	//��ʼ��OverlayWidgetController
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& Params);



protected:
	/*virtual void BeginPlay() override;*/

private:

	//����һ��UserWidget˽�б���
	UPROPERTY(EditAnywhere)
	TSubclassOf<UCNUserWidget> OverlayWidgetClass;

	//����һ��OverlayWidgetController ����
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	//����OverlayWidgetController��
	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	
};
