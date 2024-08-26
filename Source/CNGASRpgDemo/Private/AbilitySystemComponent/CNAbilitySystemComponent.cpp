// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystemComponent/CNAbilitySystemComponent.h"

void UCNAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject( this , &UCNAbilitySystemComponent::EffectApplied);
}


void UCNAbilitySystemComponent::AddCharacterAbilies(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
	for (auto AbilityClass : StartupAbilities)
	{
		//声明一个中间变量来存储GameplayAbility
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
		/*GiveAbility(AbilitySpec);*/

		//Activate GameplayAbility
		GiveAbilityAndActivateOnce( AbilitySpec);
	}



}



void UCNAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* ASC, const FGameplayEffectSpec& GES, FActiveGameplayEffectHandle AEH)
{
	//从GameplayTag容器里获取相应参数
	FGameplayTagContainer TagContainer;

	GES.GetAllAssetTags(TagContainer);

	//for (const FGameplayTag& GameplayTag : TagContainer)
	//{
	//	//将信息打印到屏幕上
	//	const FString Msg = FString::Printf(TEXT("GE_Tag : %s"), *GameplayTag.ToString());

	//	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, Msg);
	//}

	//将相应信息进行广播
	EffectAssetTags.Broadcast( TagContainer );
}
