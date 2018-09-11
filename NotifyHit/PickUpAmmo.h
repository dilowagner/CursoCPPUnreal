// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUpAmmo.generated.h"

UCLASS()
class COLISAOOVERLAP_API APickUpAmmo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpAmmo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    //Uma caixa utilizada para colis�o
	UPROPERTY(VisibleAnywhere, Category = "PickUpAmmo")
	class UBoxComponent* Colisor;

	//A malha do Objeto
	UPROPERTY(VisibleAnywhere, Category = "PickUpAmmo")
	class UStaticMeshComponent* ObjetoDoPickup;

	//Um componente de audio que ser� anexado ao pickup
	UPROPERTY(VisibleAnywhere, Category = "PickUpAmmo")
	class UAudioComponent* SomDoPickup;

	//Fun��o que ser� anexada (bind) na fun��o OnComponentBeginOverlap
	//OnComponentBeginOverlap possui muito mais par�metros que OnActorBeginOverlap
	UFUNCTION()
	void ColidiuComPickup(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
		
};
