// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SpaceshipPlayerController.generated.h"

/**
 * 
 */
UCLASS(config = Game)
class DEVOURER_API ASpaceshipPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASpaceshipPlayerController(const FObjectInitializer& initializer);

	virtual void SetupInputComponent() override;

	void MoveForward(float value);
	void MoveLeft(float value);

	//Properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementForce = 10000.0f;
	
};
