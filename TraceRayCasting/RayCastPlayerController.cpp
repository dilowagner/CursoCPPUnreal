// Fill out your copyright notice in the Description page of Project Settings.

#include "RayCastPlayerController.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"

void ARayCastPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputComponent);
	InputComponent->BindAction("Atirar", EInputEvent::IE_Released, this, &ARayCastPlayerController::AtirarRayCast);


}

void ARayCastPlayerController::AtirarRayCast()
{
	//Dist�ncia M�xima a ser percorrida pelo raio(trace)
	float Tamanho = 1000.f;

	//Neste caso foi estabelecido que a origem do radio ser� a c�mera
	//Logo achamos o vetor "frente" da C�mera(ou seja para onde a c�mera est� apontando "encarando"
	FVector Direcao = PlayerCameraManager->GetActorForwardVector();

	//Ponto de Origem, de Onde vai ser disparado o raio(Raycast)
	FVector Origem = LocalizacaoPontoDeVisaoDoPlayer;

	//Ser� o vetor de Origem somado com o vetor Direcao multiplicado por 1000, que � o tamanho
	FVector PontoFinal = LocalizacaoPontoDeVisaoDoPlayer + (RotacaoPontoDeVisaoDoPlayer.Vector() * Tamanho);

	//Variavel Struct que vai receber todos os detalhes da colisao do raio
	//Caso ocorra alguma colisao deste raio com algo.
	FHitResult ResultadodoHit;

	FCollisionQueryParams CollisionParams;

	bool ColidiuComAlgo = GetWorld()->LineTraceSingleByChannel(ResultadodoHit, Origem, PontoFinal, ECollisionChannel::ECC_Visibility, CollisionParams);
	DrawDebugLine(GetWorld(), Origem, PontoFinal, FColor::Red, true, 10.f,(uint8)0, 1.f);

	//Se o raio colidir com algo antes de terminar seu tra�o (tamanho) vai retornar true em 
	//ColidiuComAlgo
	if (ColidiuComAlgo)
	{ 
		UE_LOG(LogTemp, Error, TEXT("Ator %s"), *ResultadodoHit.Actor->GetName());
		UE_LOG(LogTemp, Error, TEXT("Local %s"), *ResultadodoHit.Location.ToString());
	}





}

void ARayCastPlayerController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);
	
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(LocalizacaoPontoDeVisaoDoPlayer, RotacaoPontoDeVisaoDoPlayer);

}
