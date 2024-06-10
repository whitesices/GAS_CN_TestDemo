// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CNGasRpgCharacterPlayer.h"
#include "Gameplay/CNGasRpgPlayerState.h"
#include "Gameplay/CNGasRpgPlayerController.h"
#include "UI/Hud/CNHUD.h"
#include "AbilitySystemComponent.h"

void ACNGasRpgCharacterPlayer::PossessedBy(AController* NewController)
{
	Super::PossessedBy( NewController );
	//����˳�ʼ��ability Actor info
	InitAbilityActorInfo();


	

}

void ACNGasRpgCharacterPlayer::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//�ͻ��˳�ʼ��Actorinfo
	InitAbilityActorInfo();

}

void ACNGasRpgCharacterPlayer::InitAbilityActorInfo()
{
	//����һ��playerstate�ı��� ���������ı�������Ҫ������PlayerState�ظ� �ᱻ����Ϊ������Ӧ�����Ա����
	ACNGasRpgPlayerState* CNPlayerState = GetPlayerState<ACNGasRpgPlayerState>();

	/*check(PlayerState)*///��ò�Ҫ��check��Ϊ �ڱ�������VS��ĳЩʱ����ڱ��벻�����if�ж�
	if (!CNPlayerState)
	{
		return;
	}
	/*PlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo( PlayerState , this );*/
	//��Ϊ�Լ������дʱ��ʾ�Ҳ�����������˲���������ķ�ʽ
	//���淢��Ҫ����AbilitySystemComponent.h
	CNPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(CNPlayerState, this);

	CNAbilitySystemComponent = CNPlayerState->GetAbilitySystemComponent();

	CNAttribuset = CNPlayerState->GetAttributeSet();


	//����UI�Ĳ���
	//��ȡController
	if (ACNGasRpgPlayerController* CNPlayerController = GetController<ACNGasRpgPlayerController>())
	{
		//��ȡHud
		if (ACNHUD* CNHUD = CNPlayerController->GetHUD<ACNHUD>())
		{
			//����hud�г�ʼ������idget�ĺ��� Ҳ��MVCʵ�ֵ����һ��
			CNHUD->InitWidget(CNPlayerController , CNPlayerState , CNAbilitySystemComponent , CNAttribuset );
		}
	}
}

//���� �Լ�������һ���»��߷���
//void ACNGasRpgCharacterPlayer::OnRep__PlayerState()
//{
//}
