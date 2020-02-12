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
	InputComponent->BindAxis("MoveUp", this, &ASpaceshipPlayerController::MoveUp);
	InputComponent->BindAxis("MoveLeft", this, &ASpaceshipPlayerController::MoveLeft);
}

void ASpaceshipPlayerController::MoveForward(float value) {
	auto pawn = GetPawn();
	if (value != 0.0f&&pawn != nullptr) {
		auto pawn = static_cast<ASpaceShip*>(GetPawn());
		auto orientation = pawn->Mesh->GetRelativeRotation();
		FVector t_ForceToAdd = orientation.RotateVector(  FVector(1, 0, 0)) * MovementForce * value;
		//pawn->SetActorLocation(FVector(0,0,0));
		pawn->Mesh->AddForce(t_ForceToAdd);
	}
}

void ASpaceshipPlayerController::MoveLeft(float value) {
	auto pawn = GetPawn();
	if (value != 0 && pawn != nullptr)
	{
		auto ship = static_cast<ASpaceShip*>(pawn);
		FVector torgue = FVector(0, 0, 1) * MovementForce * value;
		ship->Mesh->AddTorque(torgue);
	}
}

void ASpaceshipPlayerController::MoveUp(float value)
{
	auto pawn = GetPawn();

	if (value != 0 && pawn) {
		auto ship = static_cast<ASpaceShip*>(pawn);
		FVector force = FVector(0, 0, 1) * MovementForce * value;
		ship->Mesh->AddForce(force);
	}
}
