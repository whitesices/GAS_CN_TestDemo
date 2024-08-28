// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "CNInputConfig.generated.h"

class UInputAction;


USTRUCT(BlueprintType)
struct FCNInputAction
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	const class UInputAction* InputAction = nullptr;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag();
};


/**
 * 
 */
UCLASS()
class CNGASRPGDEMO_API UCNInputConfig : public UDataAsset
{
	GENERATED_BODY()

public:


	const UInputAction* FindAbilityActionForTag(const FGameplayTag& InputTag, bool bLogNotFound = false) const ;


	UPROPERTY( EditDefaultsOnly , BlueprintReadOnly )
	TArray<FCNInputAction>  AbilityInputActions;
	

};
