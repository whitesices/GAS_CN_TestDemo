// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CNGasRpgCharacterBase.h"
#include "AttributeSet/CNAttributeSet.h"
//引入AttributeSet头文件
#include "AttributeSet.h"

//引入自定义AbilityComponent的头文件
#include "AbilitySystemComponent/CNAbilitySystemComponent.h"

// Sets default values
ACNGasRpgCharacterBase::ACNGasRpgCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//新增一个组件
	 Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");

	 //添加SocketName , SocketName可以自己定义只因为方便未改成其他名字
	 const FName SocketName = "WeaponHandSocket";

	 //武器附加的人物身体上
	 Weapon->SetupAttachment(GetMesh(), SocketName);

	 //添加完后检查武器组件是否有碰撞
	 Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

UAbilitySystemComponent* ACNGasRpgCharacterBase::GetAbilitySystemComponent() const
{
	return CNAbilitySystemComponent;
}

int32 ACNGasRpgCharacterBase::GetPlayerLevel_Implementation()
{
	return 0;
}

void ACNGasRpgCharacterBase::AddCharacterAbilities()
{
	//判断是否在服务端  ， 与UE的网络同步有关系 毕竟这里做的单机即把自己本身当作server
	if (!HasAuthority())
	{
		return;
	}

	//调用执行相应的GameplayAbility
	CastChecked<UCNAbilitySystemComponent>(GetAbilitySystemComponent())->AddCharacterAbilies(StartAbilites);
}

//定义一个主要属性参数的方法
void ACNGasRpgCharacterBase::InitPrimaryAttribute() const
{
	////声明一个中间变量来容纳自己传递的技能属性
	//const UCNAttributeSet* CNAttribute = Cast<UCNAttributeSet>( CNAbilitySystemComponent->GetAttributeSet(UCNAttributeSet::StaticClass()));
	////若声明的CNAttribute有效
	//if (CNAttribuset)
	//{
	//	FGameplayEffectContextHandle EffectContextHandle = 
	//}
	//检查获取AbilitySystemComponent是否有效

	//配置主要属性
	CNApplyEffectToSelf( PrimaryAttributeEffect , 1.0f);

	//配置次要属性
	CNApplyEffectToSelf( SecondaryAttributeEffect, 1.0f);

	//配置必要属性
	CNApplyEffectToSelf( VitalAttributeEffect, 1.0f );

}


//应用GE
void ACNGasRpgCharacterBase::CNApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float level) const
{
	if (!IsValid(GetAbilitySystemComponent()))
	{
		return;
	}
	if (!PrimaryAttributeEffect)
	{
		return;
	}

	/*const*/ FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();

	//在MMC_MaxHealth中会报错找不到SourceObject的原因便是没有在这里进行相应Object的添加
	ContextHandle.AddSourceObject(this);


	const FGameplayEffectSpecHandle EffectSpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass , 1.0f , ContextHandle);

	//应用GameplayEffect
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*EffectSpecHandle.Data.Get(), GetAbilitySystemComponent());
}

