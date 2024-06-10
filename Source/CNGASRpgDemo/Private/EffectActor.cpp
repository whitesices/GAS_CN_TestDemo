// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectActor.h"
#include "AbilitySystemInterface.h"
//�����Զ����AttributeSet
#include "AttributeSet/CNAttributeSet.h"
//����AttributeSetͷ�ļ�
#include "AttributeSet.h"

// Sets default values
AEffectActor::AEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AEffectActor::OnEffectOverlap(AActor* OtherActor)
{

	//��ǰʹ�õ�Hack�ķ�ʽȥ�޸�����ֵ �� ��ȷ����������Gameplay Effect
	//����һ������ϵͳ�ӿڵı���
	IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>( OtherActor );

	//���������Ľӿڱ����Ƿ���Ч
	if (ASCInterface)
	{
		//�����ָ�����ֵ�޷���ʼ������ı���ֵ ����Ҫת��
		const UCNAttributeSet* CNrpgAttributeSet = Cast<UCNAttributeSet>( ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UCNAttributeSet::StaticClass()) );
		//�ж���������Attribute�Ƿ���Ч
		if (CNrpgAttributeSet)
		{
			//Ҫ�ǵ����*��
			UCNAttributeSet* MutableRpgAttributeSet = const_cast<UCNAttributeSet*>(CNrpgAttributeSet);
			//����Ѫ��ֵ
			MutableRpgAttributeSet->SetHealth(125.f);
			//ʹ�ôݻٵ�ǰActor
			Destroy();
		}
	}
}

// Called when the game starts or when spawned
void AEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEffectActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

