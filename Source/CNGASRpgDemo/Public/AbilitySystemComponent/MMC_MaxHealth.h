// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "MMC_MaxHealth.generated.h"

/**
 * 
 */
UCLASS()
class CNGASRPGDEMO_API UMMC_MaxHealth : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
	//构造函数
	UMMC_MaxHealth();

	//重写自定义计算的基类
	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:
	//定义一个变量来获取相应属性参数
	FGameplayEffectAttributeCaptureDefinition VigorDef;
	
};
