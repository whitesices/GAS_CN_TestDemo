// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystemComponent/CNAbilitySystemComponent.h"
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
	//暂时弃用addUobject的方式
	/*AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CNRpgAttributSets->GetHealthAttribute()).AddUObject( this , &UOverlayWidgetController::OnHealthChange);*/
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CNRpgAttributSets->GetHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			// 将自己定义的FOnAttributeValueChangeSignature 进行广播
				OnHealthChanged.Broadcast(Data.NewValue);
		}
	
	);
	//注意这里不要输入为GetMaxHealthAttributes
	/*AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CNRpgAttributSets->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::OnMaxHealthChange);*/
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CNRpgAttributSets->GetMaxHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			//将自己定义的FOnAttributeValueChangeSignature 进行广播
			OnMaxHealthChanged.Broadcast(Data.NewValue);
		}


	);



	//下面使用Lamda的表达方式
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CNRpgAttributSets->GetManaAttribute()).AddLambda([this](const FOnAttributeChangeData& Data) {

		OnManaChanged.Broadcast(Data.NewValue);

		});

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CNRpgAttributSets->GetMaxManaAttribute()).AddLambda([this](const FOnAttributeChangeData& Data )
		{
			OnMaxManaChanged.Broadcast(Data.NewValue);

		});

	//将AbilitSystemComponet中广播的消息进行绑定发送
	Cast<UCNAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda([this]( const FGameplayTagContainer& GameplayTagContainer ) {

		//在屏幕打印出相应信息
			for (const FGameplayTag& GameplayTag : GameplayTagContainer)
			{
				//GameplayAPI
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag( FName("Message") );
				//"Message.HealthPotion".MatchesTag(" Message ") 为true , "Message.HealthPotion".MatchesTag("Message.HealthPotion")为false
				if (GameplayTag.MatchesTag(MessageTag))
				{
						//1.查表
					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, GameplayTag);
						//2.将查到的结果通过委托的方式进行广播到下一层（view层)
					MessageWidgetRowDelegate.Broadcast( *Row );

				}

				




				////将信息打印到屏幕上
				//const FString Msg = FString::Printf(TEXT("GE_Tag : %s"), *GameplayTag.ToString());

				//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan, Msg);
			}

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

