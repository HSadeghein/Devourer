// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "SpaceShipPlayer.generated.h"

UCLASS()
class DEVOURER_API ASpaceShipPlayer : public APawn
{
	GENERATED_BODY()
private:
	void MoveForward(float axisValue);
	FVector _velocity;
public:
	// Sets default values for this pawn's properties
	ASpaceShipPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* mesh;
};
