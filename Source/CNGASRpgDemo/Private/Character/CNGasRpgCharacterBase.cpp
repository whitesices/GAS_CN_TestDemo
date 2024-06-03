// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CNGasRpgCharacterBase.h"

// Sets default values
ACNGasRpgCharacterBase::ACNGasRpgCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//新增一个组件
	 Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");

	 //添加SocketName , SocketName可以自己定义只因为方便未改成其他名字
	 const FName SocketName = "WeaponHandSocket";

	 //武器附加的人物身体上
	 Weapon->SetupAttachment(GetMesh(), SocketName);

	 //添加完后检查武器组件是否有碰撞
	 Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

UAbilitySystemComponent* ACNGasRpgCharacterBase::GetAbilitySystemComponent() const
{
	return CNAbilitySystemComponent;
}

