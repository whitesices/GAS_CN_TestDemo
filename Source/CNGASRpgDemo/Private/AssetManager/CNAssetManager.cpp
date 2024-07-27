// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetManager/CNAssetManager.h"
//引入自定义的GamplayTag 类
#include "AbilitySystemComponent/AuraGameplayTags.h"

UCNAssetManager& UCNAssetManager::Get()
{
	// TODO: 在此处插入 return 语句

	/*if (!GEngine)
	{
		return ;
	}*/
	//检查GEngine是否有效
	check(GEngine);

	UCNAssetManager* CNAssetManager = Cast<UCNAssetManager>(GEngine->AssetManager);

	return *CNAssetManager;

}

void UCNAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	//调用初始化Gameplaytag的方法
	FAuraGameplayTags::InitializeNativeGameplayTags();
}
