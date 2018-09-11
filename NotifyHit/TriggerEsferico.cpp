// Fill out your copyright notice in the Description page of Project Settings.

#include "TriggerEsferico.h"
#include "Engine/Engine.h"

void ATriggerEsferico::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ATriggerEsferico::ColisaoDetectada);
	//Fun��o OnActorBeginOverlap � Delegate
	//Assim ele permite que outras fun��es possam ser anexadas a ela
	//Logo quando o evento de overlap ocorrer a fun��o OnActorBeginOverlap vai ser disparada
	//e todas as outras fun��es que tiverem sido anexadas a ela via delegate tamb�m ser�o chamadas
	//assim estamos indicando que a fun��o ColisaoDetectada seja chamada quando a funcao
	//OnActorBeginOverlap for chamada.
	//Isso � realizado passando o endere�o da fun��o com &
	//this indica que queremo que este objeto Trigger seja considerado ao anexar fun��o
	//Logo � neste(this) objeto que caso o evento overlap ocorra ele vai chamar a fun��o 
	//OnActorBeginOverlap que consequentemente vai chamar a fun��o ColisaoDetectada
	// Pois voc� programou isso! via Delegate! :)
	OnActorEndOverlap.AddDynamic(this, &ATriggerEsferico::DeixouDeColidir);
	//Anexando uma fun��o � fun��o OnActorEndOverlap para que ela seja acionada quando esta fun��o ocorrer.
}

void ATriggerEsferico::ColisaoDetectada(AActor* me, AActor* other)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, 
		FString::Printf(TEXT("Entrou no Trigger Em Overlap em: %s"), *GetActorLocation().ToString()));
	//other->Destroy();
	//Quando o player ou algum elemento tocar o Trriger ser� destruido e uma mensagem aparecer� na tela
}

void ATriggerEsferico::DeixouDeColidir(AActor * me, AActor * other)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Deixou de Sobrepor(Overlap) O trigger em: %s"), *GetActorLocation().ToString()));

}





