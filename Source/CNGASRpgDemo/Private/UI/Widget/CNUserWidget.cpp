// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/CNUserWidget.h"

void UCNUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;

	WidgetControllerSet();
}
