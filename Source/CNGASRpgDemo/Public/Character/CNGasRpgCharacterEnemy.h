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

	//继承实现高亮
	void HighLight_Implementation() override;

	//继承实现不高亮
	void UnHighLight_Implementation() override;


	
};
