// Fill out your copyright notice in the Description page of Project Settings.

#include "TraceRayCastingGameModeBase.h"
#include "RayCastPlayerController.h"

//Indica qual ser� a classe padr�o do PlayerController neste GameMode
ATraceRayCastingGameModeBase::ATraceRayCastingGameModeBase()
{
	PlayerControllerClass = ARayCastPlayerController::StaticClass();
}

