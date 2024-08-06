// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AttributeMenuWidgetController.h"
//引入自定义的AttributeSet
#include "AttributeSet/CNAttributeSet.h"
#include "AssetManager/AttributeInfo.h"
//引入自定义的GameplayTag
#include "AbilitySystemComponent/AuraGameplayTags.h"

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	/*Super::BroadcastInitialValues();*/
	//声明一个AttributeSet的变量
	UCNAttributeSet* CAS = CastChecked<UCNAttributeSet>( AttributeSet );//这个AttributeSet 是父类CNWidgetController中定义的AttributeSet变量
	//判断AttributeInfo是否为空
	if (!AttributeInfo)
	{
		return;
	}

	FCNAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(FAuraGameplayTags::Get().Attribute_Primary_Strength);//调用自定义的AttributeInfo中FindAttributeInfoForTag的方法

	Info.AttributeValue = CAS->GetStrength();//将获得的strength的值传给AttributeInfo
	AttributeInfoDelegate.Broadcast(Info);//进行广播
	

}

void UAttributeMenuWidgetController::BindCallbackToDepencies()
{
	/*Super::BindCallbackToDepencies();*/
}
