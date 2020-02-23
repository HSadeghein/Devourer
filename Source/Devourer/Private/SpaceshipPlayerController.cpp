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
	InputComponent->BindAction("Break", IE_Pressed, this, &ASpaceshipPlayerController::BreakStart);
	InputComponent->BindAction("Break", IE_Released, this, &ASpaceshipPlayerController::BreakEnd);

}

void ASpaceshipPlayerController::MoveForward(float value) {
	auto pawn = GetPawn();
	if (value != 0.0f && pawn != nullptr) {
		auto pawn = static_cast<ASpaceShip*>(GetPawn());
		auto orientation = pawn->Mesh->GetRelativeRotation();
		FVector t_ForceToAdd = orientation.RotateVector(FVector(1, 0, 0)) * LinearForce * value * throttle;
		//pawn->SetActorLocation(FVector(0,0,0));
		pawn->Mesh->AddForce(t_ForceToAdd);
	}
}

void ASpaceshipPlayerController::MoveLeft(float value) {
	auto pawn = GetPawn();
	if (value != 0 && pawn != nullptr)
	{
		auto ship = static_cast<ASpaceShip*>(pawn);
		FVector torque = FVector(0, 0, 1) * LinearForce * value;
		ship->Mesh->AddTorque(torque);
	}
}

void ASpaceshipPlayerController::MoveUp(float value)
{
	auto pawn = GetPawn();

	if (value != 0 && pawn) {
		auto ship = static_cast<ASpaceShip*>(pawn);
		auto orien = ship->Mesh->GetRelativeRotation();
		FVector force = orien.RotateVector(FVector(0, 0, 1)) * LinearForce * value;
		ship->Mesh->AddForce(force);
	}
}

void ASpaceshipPlayerController::TiltVertical(float value)
{
	auto pawn = GetPawn();

	if (value != 0 && pawn) {
		auto ship = static_cast<ASpaceShip*>(pawn);
		auto orien = ship->Mesh->GetRelativeRotation();
		FVector torque = orien.RotateVector(FVector(0, 1, 0)) * AngularForce * value;
		ship->Mesh->AddTorque(torque);
	}
}

void ASpaceshipPlayerController::TilHorizontal(float value)
{
	auto pawn = GetPawn();

	if (value != 0 && pawn) {
		auto ship = static_cast<ASpaceShip*>(pawn);
		auto orien = ship->Mesh->GetRelativeRotation();

		FVector torque = orien.RotateVector(FVector(1, 0, 0)) * AngularForce * value;
		ship->Mesh->AddTorque(torque);
	}
}

void ASpaceshipPlayerController::Throttle(float value) {
	auto pawn = GetPawn();
	if (value != 0 && pawn != nullptr) {
		auto ship = static_cast<ASpaceShip*>(pawn);
		auto speed = getSpeed();
		//if (speed >= MAX_SPEED)
		//	return;
		auto orientation = ship->Mesh->GetRelativeRotation();

		FVector t_ForceToAdd = ship->Mesh->GetForwardVector() * LinearForce * value;
		//pawn->SetActorLocation(FVector(0,0,0));
		//ship->Mesh->AddForce(t_ForceToAdd);
		forwardForce = t_ForceToAdd;
		LinearForce = 140000;
		AngularForce = 90000;
	}
}

void ASpaceshipPlayerController::PlayerTick(float DeltaTime)
{
	//UE_LOG(LogTemp, Warning, TEXT("Your message"));
	LinearForce = 30000;
	AngularForce = 40000;
	Super::PlayerTick(DeltaTime);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Linear Force: %f"), LinearForce));
	auto pawn = GetPawn();
	auto ship = static_cast<ASpaceShip*>(pawn);
	FVector t_ForceToAdd = ship->Mesh->GetForwardVector() * LinearForce;
	ship->Mesh->AddForce(t_ForceToAdd);
}

void ASpaceshipPlayerController::BreakStart()
{
	// Use lineardamping for break
	auto pawn = GetPawn();
	if (pawn) {
		auto ship = static_cast<ASpaceShip*>(pawn);
		ship->Mesh->SetLinearDamping(3);
		ship->Mesh->SetAngularDamping(3);
	}
}

void ASpaceshipPlayerController::BreakEnd()
{
	auto pawn = GetPawn();
	if (pawn) {
		auto ship = static_cast<ASpaceShip*>(pawn);
		ship->Mesh->SetLinearDamping(0.2f);
		ship->Mesh->SetAngularDamping(0.2f);
	}
}

float ASpaceshipPlayerController::getSpeed()
{
	auto pawn = GetPawn();
	if (pawn) {
		auto ship = static_cast<ASpaceShip*>(pawn);
		auto speed = ship->Mesh->GetPhysicsLinearVelocity().Size();
		return speed;
	}
	return -1;
}

