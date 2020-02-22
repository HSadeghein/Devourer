// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "SpaceShip.generated.h"

UCLASS()
class DEVOURER_API ASpaceShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASpaceShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PossessedBy(AController* controller) override;
	
	// Cpmponents
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* Camera;


	
	//Properties
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float MovementForce = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<APawn> enemyPawn;


	//Functions
	void MoveForward(float value);
	void SpawnEnemy();

};
