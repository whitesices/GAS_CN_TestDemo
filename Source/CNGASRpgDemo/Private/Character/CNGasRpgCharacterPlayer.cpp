// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CNGasRpgCharacterPlayer.h"
#include "Gameplay/CNGasRpgPlayerState.h"
#include "Gameplay/CNGasRpgPlayerController.h"
#include "UI/Hud/CNHUD.h"
#include "AbilitySystemComponent.h"

void ACNGasRpgCharacterPlayer::PossessedBy(AController* NewController)
{
	Super::PossessedBy( NewController );
	//服务端初始化ability Actor info
	InitAbilityActorInfo();


	

}

void ACNGasRpgCharacterPlayer::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//客户端初始化Actorinfo
	InitAbilityActorInfo();

}

void ACNGasRpgCharacterPlayer::InitAbilityActorInfo()
{
	//声明一个playerstate的变量 而且声明的变量名不要与基类的PlayerState重复 会被误认为调用相应的类成员函数
	ACNGasRpgPlayerState* CNPlayerState = GetPlayerState<ACNGasRpgPlayerState>();

	/*check(PlayerState)*///最好不要用check因为 在编译是在VS中某些时候存在编译不过最好if判断
	if (!CNPlayerState)
	{
		return;
	}
	/*PlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo( PlayerState , this );*/
	//因为自己这里编写时提示我不完整类型因此采用了下面的方式
	//后面发现要引入AbilitySystemComponent.h
	CNPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(CNPlayerState, this);

	CNAbilitySystemComponent = CNPlayerState->GetAbilitySystemComponent();

	CNAttribuset = CNPlayerState->GetAttributeSet();


	//创建UI的操作
	//获取Controller
	if (ACNGasRpgPlayerController* CNPlayerController = GetController<ACNGasRpgPlayerController>())
	{
		//获取Hud
		if (ACNHUD* CNHUD = CNPlayerController->GetHUD<ACNHUD>())
		{
			//调用hud中初始化加载idget的函数 也是MVC实现的最后一环
			CNHUD->InitWidget(CNPlayerController , CNPlayerState , CNAbilitySystemComponent , CNAttribuset );
		}
	}
}

//错误 自己多输入一个下划线符号
//void ACNGasRpgCharacterPlayer::OnRep__PlayerState()
//{
//}
