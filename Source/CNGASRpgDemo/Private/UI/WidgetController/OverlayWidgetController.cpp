// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"
//�����Զ����AttributeSet�ķ���
#include "AttributeSet/CNAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	//������һ��UCNAttributeSet����Ϊ�м��������ֵ
	//ʹ��CastChecked���� ���е�ͬʱ�����м��
	UCNAttributeSet* CNRpgAtributeSets = CastChecked<UCNAttributeSet>( AttributeSet );

	//�㲥��Ӧ����,�㲥��UI����
	OnHealthChanged.Broadcast( CNRpgAtributeSets->GetHealth() );
	OnMaxHealthChanged.Broadcast(CNRpgAtributeSets->GetMaxHealth());
	OnManaChanged.Broadcast(CNRpgAtributeSets->GetMana());
	OnMaxManaChanged.Broadcast(CNRpgAtributeSets->GetMaxMana());
}

void UOverlayWidgetController::BindCallbackToDepencies()
{
	/*Super::BindCallbackToDepencies();*/

	//������һ��UCNAttributeSet����Ϊ�м��������ֵ
	UCNAttributeSet* CNRpgAttributSets = CastChecked<UCNAttributeSet>( AttributeSet );

	//�����ַ�ʽ���а� һ����AddUObject , һ���� AddLamda���ʽ
	//��ʹ��AddUObject�ķ�ʽ
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CNRpgAttributSets->GetHealthAttribute()).AddUObject( this , &UOverlayWidgetController::OnHealthChange);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(CNRpgAttributSets->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::OnMaxHealthChange);

	//����ʹ��Lamda�ı�﷽ʽ
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
	//���Լ������FOnAttributeValueChangeSignature ���й㲥
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::OnMaxHealthChange(const FOnAttributeChangeData& Data)
{
	//���Լ������FOnAttributeValueChangeSignature ���й㲥
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

