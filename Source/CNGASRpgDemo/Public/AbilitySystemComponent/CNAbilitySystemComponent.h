// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "CNAbilitySystemComponent.generated.h"

class UGameplayAbility;

DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTags, const FGameplayTagContainer&);

/**
 * 
 */
UCLASS()
class CNGASRPGDEMO_API UCNAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:

	//技能对象信息设置
	void AbilityActorInfoSet();

	//定义相应委托
	FEffectAssetTags EffectAssetTags;

	//定义一个增加技能的方法
	void AddCharacterAbilies( const TArray<TSubclassOf<UGameplayAbility>> &StartupAbilities);

protected:
	void EffectApplied(UAbilitySystemComponent* ASC, const FGameplayEffectSpec& GES, FActiveGameplayEffectHandle AEH);
	
};
