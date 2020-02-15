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
	void MoveUp(float value);
	void TiltVertical(float value);
	void TilHorizontal(float value);
	//Properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementForce = 100000.0f;
	
};
