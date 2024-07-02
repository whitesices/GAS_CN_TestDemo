// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "CNGasRpgCharacterBase.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayEffect;

//需要继承ability的相应接口
UCLASS()
class CNGASRPGDEMO_API ACNGasRpgCharacterBase : public ACharacter , public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	ACNGasRpgCharacterBase();

	//重载获取技能系统组件的方法
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	//定义一个返回技能属性的方法
	UAttributeSet* GetAttributeSet() const
	{
		return CNAttribuset;
	}

protected:
	//定义一个初始化主要属性参数的方法
	void InitPrimaryAttribute() const;

protected:

	//新增一个武器骨骼组件UPROPERTY
	UPROPERTY( EditAnywhere , Category = "Weapon")
	TObjectPtr<USkeletalMeshComponent> Weapon;


	//声明一个技能系统组件的变量
	UPROPERTY( EditAnywhere , Category = "CNAbilitySystemComponent")
	TObjectPtr<UAbilitySystemComponent> CNAbilitySystemComponent;

	//声明一个技能属性的变量
	UPROPERTY( EditAnywhere , Category = "CNAttributeSEt")
	TObjectPtr<UAttributeSet> CNAttribuset;

	//声明一个容纳主要属性GE的类变量
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayEffect> PrimaryAttributeEffect;

};
