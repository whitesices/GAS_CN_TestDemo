// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CNGasRpgCharacterEnemy.h"

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
