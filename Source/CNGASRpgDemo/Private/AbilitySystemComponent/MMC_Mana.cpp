// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystemComponent/MMC_Mana.h"
#include "AttributeSet/CNAttributeSet.h"
//引入接口
#include "Interface/CombateInterface.h"


UMMC_Mana::UMMC_Mana()
{
	//将相应的属性值进行初始化 即捕获
	IntelligenceDef.AttributeToCapture = UCNAttributeSet::GetIntelligenceAttribute();

	//配置捕获的源
	IntelligenceDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;

	//进行拍照
	IntelligenceDef.bSnapshot = false;

	//将IntelligenceDef添加
	RelevantAttributesToCapture.Add(IntelligenceDef);
}



float UMMC_Mana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	//声明一个GameplayTag的Container 即GameplayTag的容器
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();

	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	//传递相应绑定的Tag
	FAggregatorEvaluateParameters EvaluateParameters;

	EvaluateParameters.SourceTags = SourceTags;
	EvaluateParameters.TargetTags = TargetTags;

	//定义Intelligence
	float Intelligence = 0.f;
	GetCapturedAttributeMagnitude(IntelligenceDef, Spec, EvaluateParameters, Intelligence);

	//始终让Intelligence获得最大值
	Intelligence = FMath::Max<float>(Intelligence, 0.f );

	//给level赋初值
	int32 level = 0;

	//进行判断
	if (Spec.GetContext().GetSourceObject()->Implements<UCombateInterface>())
	{
		//传递level值
		level = ICombateInterface::Execute_GetPlayerLevel(Spec.GetContext().GetSourceObject());
	}

	//注意不要运算错了变量
	return 80.f + 2*Intelligence + 10*level;
}
