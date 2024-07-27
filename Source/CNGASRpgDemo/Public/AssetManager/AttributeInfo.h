// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
//引入GameplayTag的标签
#include "GameplayTagContainer.h"
#include "AttributeInfo.generated.h"

/**
 * 
 */
//自定义个结构体
USTRUCT( BlueprintType )
struct FCNAttributeInfo
{
	GENERATED_BODY()

	//定义一个属性标签
	UPROPERTY( EditDefaultsOnly , BlueprintReadOnly )
	FGameplayTag AttributeTag = FGameplayTag();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly )
	FText AttributeName = FText();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly )
	FText AttributeDescription = FText();

	UPROPERTY( BlueprintReadOnly )
	float AttributeValue = 0.f;
};



UCLASS()
class CNGASRPGDEMO_API UAttributeInfo : public UDataAsset
{
	GENERATED_BODY()

public:
	//自定义一个方法通过标签去寻找相应参数
	FCNAttributeInfo FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound = false ) const;

	//声明一个数组来存储属性信息
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly )
	TArray<FCNAttributeInfo> AttributeInformation;
	
};
