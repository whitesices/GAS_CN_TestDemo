// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"
//引入自定义的AttributeSet的方法
#include "AttributeSet/CNAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	//新声明一个UCNAttributeSet来作为中间变量传递值
	//使用CastChecked方法 运行的同时并进行检查
	UCNAttributeSet* CNRpgAtributeSets = CastChecked<UCNAttributeSet>( AttributeSet );

	//广播相应参数,广播给UI层面
	OnHealthChanged.Broadcast( CNRpgAtributeSets->GetHealth() );
	OnMaxHealthChanged.Broadcast(CNRpgAtributeSets->GetMaxHealth());
	OnManaChanged.Broadcast(CNRpgAtributeSets->GetMana());
	OnMaxManaChanged.Broadcast(CNRpgAtributeSets->GetMaxMana());
}

void UOverlayWidgetController::BindCallbackToDepencies()
{
	/*Super::BindCallbackToDepencies();*/

	//新声明一个UCNAttributeSet来作为中间变量传递值
	UCNAttributeSet* CNRpgAttributSets = CastChecked<UCNAttributeSet>( AttributeSet );

	//用两种方式进行绑定 一种是AddUObject , 一种是 AddLamda表达式
	//先使用AddUObject的方式
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CNRpgAttributSets->GetHealthAttribute()).AddUObject( this , &UOverlayWidgetController::OnHealthChange);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CNRpgAttributSets->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::OnMaxHealthChange);

	//下面使用Lamda的表达方式
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CNRpgAttributSets->GetManaAttribute()).AddLambda([this](const FOnAttributeChangeData& Data) {

		OnManaChanged.Broadcast(Data.NewValue);

		});

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CNRpgAttributSets->GetMaxManaAttribute()).AddLambda([this](const FOnAttributeChangeData& Data )
		{
			OnMaxManaChanged.Broadcast(Data.NewValue);

		});

}

void UOverlayWidgetController::OnHealthChange(const FOnAttributeChangeData& Data)
{
	//将自己定义的FOnAttributeValueChangeSignature 进行广播
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::OnMaxHealthChange(const FOnAttributeChangeData& Data)
{
	//将自己定义的FOnAttributeValueChangeSignature 进行广播
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

