// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystemComponent/MMC_MaxHealth.h"
#include "AttributeSet/CNAttributeSet.h"
#include "Interface/CombateInterface.h"

UMMC_MaxHealth::UMMC_MaxHealth()
{
	//将相应的属性值进行初始化赋值 即捕获
	VigorDef.AttributeToCapture = UCNAttributeSet::GetVigorAttribute();
	//配置捕获的源
	VigorDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	//进行拍照
	VigorDef.bSnapshot = false;

	RelevantAttributesToCapture.Add( VigorDef );

}

float UMMC_MaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	//声明一个GameplayTag的container 即gameplayTag的容器
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();

	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	//传递相应绑定的tag
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = SourceTags;
	EvaluateParameters.TargetTags = TargetTags;

	//定义Vigor
	float Vigor = 0.f;
	GetCapturedAttributeMagnitude(VigorDef, Spec, EvaluateParameters, Vigor);

	//始终让Vigor获取最大值
	Vigor = FMath::Max<float>(Vigor, 0.f);

	//给level赋初始值
	int32 level = 0;
	//进行判断
	if ( Spec.GetContext().GetSourceObject()->Implements<UCombateInterface>() )
	{
		//传递level值
		level = ICombateInterface::Execute_GetPlayerLevel(Spec.GetContext().GetSourceObject());
	}

	//返回自己的计算规则
	return  80.f + 2 * Vigor + 10 * level;

}
