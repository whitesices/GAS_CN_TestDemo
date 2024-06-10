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

	//��д��������
	virtual void PossessedBy( AController* NewController ) override;

	virtual void OnRep_PlayerState() override;

	//��װһ��InitAbilityActorInfo
	void InitAbilityActorInfo();

	
};
