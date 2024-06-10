// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectActor.h"
#include "AbilitySystemInterface.h"
//引入自定义的AttributeSet
#include "AttributeSet/CNAttributeSet.h"
//引入AttributeSet头文件
#include "AttributeSet.h"

// Sets default values
AEffectActor::AEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AEffectActor::OnEffectOverlap(AActor* OtherActor)
{

	//当前使用的Hack的方式去修改属性值 ， 正确的做法是用Gameplay Effect
	//声明一个技能系统接口的变量
	IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>( OtherActor );

	//检验声明的接口变量是否有效
	if (ASCInterface)
	{
		//当出现该类型值无法初始化后面的变量值 则需要转换
		const UCNAttributeSet* CNrpgAttributeSet = Cast<UCNAttributeSet>( ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UCNAttributeSet::StaticClass()) );
		//判断自声明的Attribute是否有效
		if (CNrpgAttributeSet)
		{
			//要记得添加*号
			UCNAttributeSet* MutableRpgAttributeSet = const_cast<UCNAttributeSet*>(CNrpgAttributeSet);
			//更新血量值
			MutableRpgAttributeSet->SetHealth(125.f);
			//使用摧毁当前Actor
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

