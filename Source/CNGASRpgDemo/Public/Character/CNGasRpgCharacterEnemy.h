// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CNGasRpgCharacterBase.h"
#include "Interface/EnemyInterface.h"
#include "CNGasRpgCharacterEnemy.generated.h"

/**
 * 
 */
UCLASS()
class CNGASRPGDEMO_API ACNGasRpgCharacterEnemy : public ACNGasRpgCharacterBase ,public IEnemyInterface
{
	GENERATED_BODY()

	//给Enemy类一个构造函数
public:
	//自定义的构造函数
	ACNGasRpgCharacterEnemy();

	//继承实现高亮
	void HighLight_Implementation() override;

	//继承实现不高亮
	void UnHighLight_Implementation() override;

protected:

	//重载beginplay方法
	virtual void BeginPlay() override;


	
};
