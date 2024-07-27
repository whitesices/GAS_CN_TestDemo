// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetManager/AttributeInfo.h"

FCNAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	/*return FCNAttributeInfo();*/

	for ( const FCNAttributeInfo& AttributeInfo : AttributeInformation)
	{
		//判断AttributeTag是否能匹配上
		//因为要返回值 所以需要将定义的变量定义为引用加 const
		if (AttributeInfo.AttributeTag.MatchesTagExact(AttributeTag))
		{

			return AttributeInfo;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("找不到属性信息通过[%s]在AttributeInfo[%s]" ) , *AttributeTag.ToString() , *GetNameSafe(this) );
	}
	
	//上述都不行的情况下返回一个空值
	return FCNAttributeInfo();
}
