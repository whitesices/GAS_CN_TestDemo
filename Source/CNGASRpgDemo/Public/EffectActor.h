// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "ActiveGameplayEffectHandle.h"
#include "ActiveGameplayEffectHandle.h"
#include "EffectActor.generated.h"

class UAbilitySystemComponent;
class UGameplayEffect;


UENUM( BlueprintType )
enum class EEffectRemovePolicy : uint8
{
	Remove,
	DoNotRemove
};


UCLASS()
class CNGASRPGDEMO_API AEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEffectActor();

	//自定义一个EffectActor交互的函数方法
	UFUNCTION(BlueprintCallable , Category = "EffectActor")
	void OnEffectOverlap( AActor* OtherActor , TSubclassOf<UGameplayEffect> EffectToApply );

	UFUNCTION( BlueprintCallable )
	void RemoveEffect(AActor* OtherActor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	TMap< UAbilitySystemComponent*, FActiveGameplayEffectHandle > ActiveEffectHandleMap;


	UPROPERTY( EditAnywhere )
	EEffectRemovePolicy EffectRemovePolicy;

};
