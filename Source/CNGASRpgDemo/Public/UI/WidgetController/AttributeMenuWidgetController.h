// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/CNWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"


struct FCNAttributeInfo;
class UAttributeInfo;

//新建一个委托
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam( FAttributeInfoSignature, const FCNAttributeInfo&, Info) ;

/**
 * 
 */
UCLASS( BlueprintType , Blueprintable )
class CNGASRPGDEMO_API UAttributeMenuWidgetController : public UCNWidgetController
{
	GENERATED_BODY()

public:
	//继承CNWidgetController中的绑定和广播的方法
	virtual void BroadcastInitialValues() override;

	virtual void BindCallbackToDepencies() override;


	UPROPERTY( BlueprintAssignable , Category = "GAS|Attributes")
	FAttributeInfoSignature AttributeInfoDelegate;
	
protected:

	UPROPERTY( EditDefaultsOnly )
	TObjectPtr<UAttributeInfo>  AttributeInfo;

};
