// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CNGasRpgCharacterBase.h"
#include "CNGasRpgCharacterPlayer.generated.h"

/**
 * 
 */
UCLASS()
class CNGASRPGDEMO_API ACNGasRpgCharacterPlayer : public ACNGasRpgCharacterBase
{
	GENERATED_BODY()

public:

	//重写两个方法
	virtual void PossessedBy( AController* NewController ) override;

	virtual void OnRep_PlayerState() override;

	//封装一个InitAbilityActorInfo
	void InitAbilityActorInfo();

	//复写相应的方法
	virtual int32 GetPlayerLevel_Implementation() override;
	
};
