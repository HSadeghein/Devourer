// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceshipPlayerController.h"
#include "SpaceShip.h"

ASpaceshipPlayerController::ASpaceshipPlayerController(const FObjectInitializer& initializer) : Super(initializer) {
	
}
void ASpaceshipPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputComponent);
	InputComponent->BindAxis("MoveForward", this, &ASpaceshipPlayerController::MoveForward);
}

void ASpaceshipPlayerController::MoveForward(float value) {
	FVector t_ForceToAdd = FVector(1, 0, 0) * MovementForce * value;
	auto pawn = GetPawn();
	if (value != 0.0f&&pawn != nullptr) {
		auto pawn = static_cast<ASpaceShip*>(GetPawn());
		//pawn->SetActorLocation(FVector(0,0,0));
		pawn->Mesh->AddForce(t_ForceToAdd);
	}
}
