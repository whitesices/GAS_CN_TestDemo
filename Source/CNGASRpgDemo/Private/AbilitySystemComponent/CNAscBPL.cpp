// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystemComponent/CNAscBPL.h"
#include "Kismet/GameplayStatics.h"
#include "UI/Hud/CNHUD.h"
#include "Gameplay/CNGasRpgPlayerState.h"
//引入WidgetController
#include "UI/WidgetController/CNWidgetController.h"

UOverlayWidgetController* UCNAscBPL::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController( WorldContextObject , 0 ) )
	{
		if (ACNHUD* CNHud = Cast<ACNHUD>(PC->GetHUD()))
		{
			//配置FwidgetControllerParams中的多个属性
			ACNGasRpgPlayerState* PS = PC->GetPlayerState< ACNGasRpgPlayerState >();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();



			//局部定义一个WidgetControllerParams变量
			const FWidgetControllerParams WidgetControllerParams( PC , PS , ASC , AS );

			

			//返回获取的OverlayWidgetController
			return CNHud->GetOverlayWidgetController( WidgetControllerParams );
		}
	}



	//否则返回空指针
	return nullptr;
}

UAttributeMenuWidgetController* UCNAscBPL::GetAttributeWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (ACNHUD* CNHud = Cast<ACNHUD>(PC->GetHUD()))
		{
			//配置FWidgetControllerParams中的多个属性
			ACNGasRpgPlayerState* PS = PC->GetPlayerState< ACNGasRpgPlayerState >();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet( );




			//局部定义一个WidgetControllerParams变量
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);


			return CNHud->GetAttributeWidgetController( WidgetControllerParams );
		}
	}



	return nullptr;
}
