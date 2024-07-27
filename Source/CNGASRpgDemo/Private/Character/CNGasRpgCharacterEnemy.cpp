// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CNGasRpgCharacterEnemy.h"
#include "AbilitySystemComponent/CNAbilitySystemComponent.h"
#include "AttributeSet/CNAttributeSet.h"

ACNGasRpgCharacterEnemy::ACNGasRpgCharacterEnemy()
{
	//创建相应的组件和属性
	CNAbilitySystemComponent = CreateDefaultSubobject<UCNAbilitySystemComponent>("AbilitySystemComponent");
	CNAttribuset = CreateDefaultSubobject<UCNAttributeSet>("AttributeSet");

	//打开网络同步
	CNAbilitySystemComponent->SetIsReplicated(true);

	//AbilitySystemComponent的网络同步模式
	CNAbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	

}

void ACNGasRpgCharacterEnemy::HighLight_Implementation()
{
	/*IEnemyInterface::HighLight_Implementation();*/
	//在敌人基类中实现高亮操作
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(250);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(250);
}

void ACNGasRpgCharacterEnemy::UnHighLight_Implementation()
{
	/*IEnemyInterface::UnHighLight_Implementation();*/
	//在敌人基类中实现不高亮操作
	GetMesh()->SetRenderCustomDepth(false);
	GetMesh()->SetCustomDepthStencilValue(0);
	Weapon->SetRenderCustomDepth(false);
	Weapon->SetCustomDepthStencilValue(0);
}

int32 ACNGasRpgCharacterEnemy::GetPlayerLevel_Implementation()
{
	//返回在敌人类中定义的Level变量
	return Level;
}

//重载的BeginPlay方法
void ACNGasRpgCharacterEnemy::BeginPlay()
{
	Super::BeginPlay();

	//调用abilitySystemComponent 初始化技能Actor的信息
	CNAbilitySystemComponent->InitAbilityActorInfo( this , this );
	//调用AbilitySystemComponent初始化actor信息的方法
	/*CNAbilitySystemComponent->AbilityActorInfoSet;*/
	Cast<UCNAbilitySystemComponent>(CNAbilitySystemComponent)->AbilityActorInfoSet();
	//在子类的beginplay中去调用
	InitPrimaryAttribute();
}
