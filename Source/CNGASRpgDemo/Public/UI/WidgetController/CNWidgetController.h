// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CNWidgetController.generated.h"

/**
 * 
 */
class UAbilitySystemComponent;
class UAttributeSet;


//�¶���һ��U �ṹ��
USTRUCT( BlueprintType )
struct FWidgetControllerParams
{
	GENERATED_BODY()

	//����һ���޲ι��캯��
	FWidgetControllerParams(){}
	//����һ���вι��캯��
	FWidgetControllerParams( APlayerController* PC , APlayerState* PS , UAbilitySystemComponent* ASC , UAttributeSet* AS):PlayerController(PC), PlayerState(PS), AbilitySystemComponent(ASC), AttributeSet(AS)
	{}
	//��ס������Ҫ��Public����������
public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere , Category = "WidgetController")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere , Category = "WidgetController")
	TObjectPtr<APlayerState> PlayerState = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere ,Category = "WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet = nullptr;

};


//ʹ��Blueprintable ������ͼ��
UCLASS( Blueprintable )
class CNGASRPGDEMO_API UCNWidgetController : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION( BlueprintCallable )
	void SetWidgetControllerParams(const FWidgetControllerParams& WCParams);

protected:

	//������һ��PlayerController����
	UPROPERTY( BlueprintReadOnly , Category = "WidgetController")
	TObjectPtr<APlayerController> PlayerController;

	//����һ��PlayerSate�ı���
	UPROPERTY( BlueprintReadOnly , Category = "WidgetController")
	TObjectPtr<APlayerState> PlayerState;

	//����һ��AbilitySystemComponent�ı���
	UPROPERTY( BlueprintReadOnly , Category = "WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	//����һ��AttributeSet�ı���
	UPROPERTY( BlueprintReadOnly , Category = "WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet;
	
};
