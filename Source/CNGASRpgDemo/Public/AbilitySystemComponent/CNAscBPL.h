// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AbilitySystemComponent.h"
#include "CNAscBPL.generated.h"


class UOverlayWidgetController;
class UAttributeMenuWidgetController;
/**
 * 
 */
UCLASS()
class CNGASRPGDEMO_API UCNAscBPL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION( BlueprintPure , Category = "CNAbilitySystemLibrary|WidgetController" , meta = (DefaultToSelf = "WorldContextObject") )
	static UOverlayWidgetController* GetOverlayWidgetController(const UObject* WorldContextObject);

	//新建获取AttributeMenuWidgetController的方法
	UFUNCTION( BlueprintPure , Category = "CNAbilitySystemLibrary|WidgetController" , meta = (DefaultToSelf = "WorldContextObject") )
	static UAttributeMenuWidgetController* GetAttributeWidgetController(const UObject* WorldContextObject);
	
};
