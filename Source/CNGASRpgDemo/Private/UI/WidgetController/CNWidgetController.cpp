// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/CNWidgetController.h"

void UCNWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UCNWidgetController::BroadcastInitialValues()
{

}

void UCNWidgetController::BindCallbackToDepencies()
{

}
