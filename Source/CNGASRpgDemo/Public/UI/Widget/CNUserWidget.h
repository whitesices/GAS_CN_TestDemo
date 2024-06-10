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
	//�Զ���һ������WigetController�ĺ���
	UFUNCTION( BlueprintCallable , Category="CNWdiget")
	void SetWidgetController(UObject* InWidgetController);

	//����һ��Controller����
	UPROPERTY( BlueprintReadOnly )
	TObjectPtr<UObject> WidgetController;

protected:
	//����һ��WidgetController����
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
	
};
