// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AttributeMenuWidgetController.h"
//引入自定义的AttributeSet
#include "AttributeSet/CNAttributeSet.h"
#include "AssetManager/AttributeInfo.h"
//引入自定义的GameplayTag
#include "AbilitySystemComponent/AuraGameplayTags.h"
#include "AbilitySystemComponent/CNAbilitySystemComponent.h"

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	/*Super::BroadcastInitialValues();*/
	//声明一个AttributeSet的变量
	UCNAttributeSet* CAS = CastChecked<UCNAttributeSet>( AttributeSet );//这个AttributeSet 是父类CNWidgetController中定义的AttributeSet变量
	////判断AttributeInfo是否为空
	//if (!AttributeInfo)
	//{
	//	return;
	//}

	//FCNAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(FAuraGameplayTags::Get().Attribute_Primary_Strength);//调用自定义的AttributeInfo中FindAttributeInfoForTag的方法

	//Info.AttributeValue = CAS->GetStrength();//将获得的strength的值传给AttributeInfo
	//AttributeInfoDelegate.Broadcast(Info);//进行广播

	//判断AttributeInfo是否为空
	if (!AttributeInfo)
	{
		return;
	}

	//遍历查找建立映射中所存储的Tag 并将相应数据传出
	for ( auto AttributePair : CAS->TagToAttributes)
	{
		//获取Tag
		const FGameplayTag GameplayTag = AttributePair.Key;

		//通过Tag找到对应属性信息
		FCNAttributeInfo CNAttributeInfo = AttributeInfo->FindAttributeInfoForTag(GameplayTag);

		CNAttributeInfo.AttributeValue = AttributePair.Value().GetNumericValue(CAS);

		//将获得Info广播
		AttributeInfoDelegate.Broadcast(CNAttributeInfo);

		/*BroadcastAttributeInfoByCN(AttributePair.Key, AttributePair.Value(), CAS);*/
		/*BroadCastAttributeInfoCN(AttributePair.Key, AttributePair.Value() );*/

	}

}

void UAttributeMenuWidgetController::BindCallbackToDepencies()
{
	/*Super::BindCallbackToDepencies();*/

	//声明AbilitySystemComponent
	UCNAttributeSet* CAS = CastChecked<UCNAttributeSet>(AttributeSet);

	if (!AttributeInfo)
	{
		return;
	}

	//循环遍历获取value
	for (auto AttributePair : CAS->TagToAttributes)
	{
		////获取Tag
		const FGameplayTag GameplayTag = AttributePair.Key;

		////通过Tag找到对应属性信息
		FCNAttributeInfo CNAttributeInfo = AttributeInfo->FindAttributeInfoForTag(GameplayTag);

		CNAttributeInfo.AttributeValue = AttributePair.Value().GetNumericValue(CAS);


		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributePair.Value() ).AddLambda( [this , AttributePair]( const FOnAttributeChangeData& Data )
			{
				//////获取Tag
				////const FGameplayTag GameplayTag = AttributePair.Key;

				//备注 ：这里因为未将修改参数传入所以未修改 成功 且不知道为何自定义的函数 一直显示无法重载 待解决
				UCNAttributeSet* CAS = CastChecked<UCNAttributeSet>(AttributeSet);

				////通过Tag找到对应属性信息
				FCNAttributeInfo AttributeInfos = AttributeInfo->FindAttributeInfoForTag(AttributePair.Key);
				AttributeInfos.AttributeValue = AttributePair.Value().GetNumericValue(CAS);

				//将获得Info广播
				AttributeInfoDelegate.Broadcast(AttributeInfos);
			}
		
		);

	}
}

//void UAttributeMenuWidgetController::BroadCastAttributeInfoCN(const FGameplayTag& Gaemplay, FGameplayAttribute GameplayAttribute)
//{
//	UCNAttributeSet* CAS = CastChecked<UCNAttributeSet>(AttributeSet);
//	//通过Tag找到对应属性信息
//	FCNAttributeInfo CNAttributeInfo = AttributeInfo->FindAttributeInfoForTag(Gaemplay);
//
//	CNAttributeInfo.AttributeValue = GameplayAttribute.GetNumericValue(CAS);
//
//	//将获得Info广播
//	AttributeInfoDelegate.Broadcast(CNAttributeInfo);
//}



//void UAttributeMenuWidgetController::BroadcastAttributeInfoByCN(const FGameplayTag& GameplayTag,FGameplayAttribute GameplayAttribute , UCNAttributeSet* AS )
//{
//	/*UCNAttributeSet* AS = CastChecked<UCNAttributeSet>(AttributeSet);*/
//	//通过Tag找到对应属性信息
//	FCNAttributeInfo CNAttributeInfo = AttributeInfo->FindAttributeInfoForTag(GameplayTag);
//
//	CNAttributeInfo.AttributeValue = GameplayAttribute.GetNumericValue(AS);
//
//	//将获得Info广播
//	AttributeInfoDelegate.Broadcast(CNAttributeInfo);
//}
