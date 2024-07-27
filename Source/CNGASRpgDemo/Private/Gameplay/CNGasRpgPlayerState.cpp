// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/CNGasRpgPlayerState.h"
#include "AbilitySystemComponent/CNAbilitySystemComponent.h"
#include "AttributeSet/CNAttributeSet.h"
//引入虚幻联网头文件
#include "Net/UnrealNetwork.h"

ACNGasRpgPlayerState::ACNGasRpgPlayerState()
{
	//设置网络更新频率
	NetUpdateFrequency = 100.f;

	//创建技能系统组件以及属性
	CNAbilitySystemComponent = CreateDefaultSubobject<UCNAbilitySystemComponent>( "AbilitySystemComponent");
	CNAttributeSet = CreateDefaultSubobject<UCNAttributeSet>("AttributeSet");
	//打开网络同步模式
	CNAbilitySystemComponent->SetIsReplicated(true);
}


UAbilitySystemComponent* ACNGasRpgPlayerState::GetAbilitySystemComponent() const
{
	//返回自定义的系统技能组件变量
	return CNAbilitySystemComponent;
}

void ACNGasRpgPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	//将level数据做一个同步的处理
	DOREPLIFETIME( ACNGasRpgPlayerState, Level );

	
}

void ACNGasRpgPlayerState::OnRep_Level(int32 OldLevel)
{
	return;
}
