// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceshipPlayerController.h"
#include "SpaceShip.h"

ASpaceshipPlayerController::ASpaceshipPlayerController(const FObjectInitializer& initializer) : Super(initializer) {
	
}
void ASpaceshipPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputComponent);
	//InputComponent->BindAxis("MoveForward", this, &ASpaceshipPlayerController::MoveForward);
	InputComponent->BindAxis("MoveUp", this, &ASpaceshipPlayerController::MoveUp);
	//InputComponent->BindAxis("MoveLeft", this, &ASpaceshipPlayerController::MoveLeft);
	InputComponent->BindAxis("TiltVertical", this, &ASpaceshipPlayerController::TiltVertical);
	InputComponent->BindAxis("TiltHorizontal", this, &ASpaceshipPlayerController::TilHorizontal);

	InputComponent->BindAxis("Throttle", this, &ASpaceshipPlayerController::Throttle);

}

void ASpaceshipPlayerController::MoveForward(float value) {
	auto pawn = GetPawn();
	if (value != 0.0f&&pawn != nullptr) {
		auto pawn = static_cast<ASpaceShip*>(GetPawn());
		auto orientation = pawn->Mesh->GetRelativeRotation();
		FVector t_ForceToAdd = orientation.RotateVector( FVector(1, 0, 0)) * MovementForce * value * throttle;
		//pawn->SetActorLocation(FVector(0,0,0));
		pawn->Mesh->AddForce(t_ForceToAdd);
	}
}

void ASpaceshipPlayerController::MoveLeft(float value) {
	auto pawn = GetPawn();
	if (value != 0 && pawn != nullptr)
	{
		auto ship = static_cast<ASpaceShip*>(pawn);
		FVector torque = FVector(0, 0, 1) * MovementForce * value;
		ship->Mesh->AddTorque(torque);
	}
}

void ASpaceshipPlayerController::MoveUp(float value)
{
	auto pawn = GetPawn();

	if (value != 0 && pawn) {
		auto ship = static_cast<ASpaceShip*>(pawn);
		auto orien = ship->Mesh->GetRelativeRotation();
		FVector force = orien.RotateVector(FVector(0, 0, 1)) * MovementForce * value;
		ship->Mesh->AddForce(force);
	}
}

void ASpaceshipPlayerController::TiltVertical(float value)
{
	auto pawn = GetPawn();

	if (value != 0 && pawn) {
		auto ship = static_cast<ASpaceShip*>(pawn);
		auto orien = ship->Mesh->GetRelativeRotation();
		FVector torque = orien.RotateVector(FVector(0, 1, 0)) * MovementForce * value;
		ship->Mesh->AddTorque(torque);
	}
}

void ASpaceshipPlayerController::TilHorizontal(float value)
{
	auto pawn = GetPawn();

	if (value != 0 && pawn) {
		auto ship = static_cast<ASpaceShip*>(pawn);
		auto orien = ship->Mesh->GetRelativeRotation();
		
		FVector torque = orien.RotateVector(FVector(1, 0, 0)) * MovementForce * value;
		ship->Mesh->AddTorque(torque);
	}
}

void ASpaceshipPlayerController::Throttle(float value) {
	auto pawn = GetPawn();
	if (value != 0 && pawn != nullptr) {
		auto pawn = static_cast<ASpaceShip*>(GetPawn());
		auto orientation = pawn->Mesh->GetRelativeRotation();
		FVector t_ForceToAdd = pawn->Mesh->GetForwardVector() * MovementForce*value;
		//pawn->SetActorLocation(FVector(0,0,0));
		pawn->Mesh->AddForce(t_ForceToAdd);
	}
}

