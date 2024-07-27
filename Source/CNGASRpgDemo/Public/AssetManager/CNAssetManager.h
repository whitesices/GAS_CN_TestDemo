// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "CNAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class CNGASRPGDEMO_API UCNAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	static UCNAssetManager& Get();

protected:
	virtual void StartInitialLoading() override;
	
};
