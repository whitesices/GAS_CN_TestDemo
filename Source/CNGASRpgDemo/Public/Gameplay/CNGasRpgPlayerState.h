// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "CNGasRpgPlayerState.generated.h"


//������Ӧ����
class UAbilitySystemComponent;
class UAttributeSet;

/**
 * 
 */
UCLASS()
class CNGASRPGDEMO_API ACNGasRpgPlayerState : public APlayerState , public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	ACNGasRpgPlayerState();

	//���ػ�ȡϵͳ����ķ���
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	//����һ����ȡ�������Եķ���
	UAttributeSet* GetAttributeSet() const
	{
		return CNAttributeSet;
	}
	//����һ������ϵͳ�������
	UPROPERTY( EditAnywhere , Category = "CNAbilitySystemComponent")
	TObjectPtr<UAbilitySystemComponent> CNAbilitySystemComponent;

	//����һ���������Ա���
	UPROPERTY( EditAnywhere , Category = "CNAttributeSet")
	TObjectPtr<UAttributeSet> CNAttributeSet;
	
};
