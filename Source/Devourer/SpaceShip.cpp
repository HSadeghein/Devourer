// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceShip.h"
#include "Components/InputComponent.h"

// Sets default values
ASpaceShip::ASpaceShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//Initialize The Componenets
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	//Set The Hirarchy
	RootComponent = Mesh;
	SpringArm->SetupAttachment(Mesh);
	Camera->SetupAttachment(SpringArm);

	//Set physics
	Mesh->SetSimulatePhysics(true);
	MovementForce = 10000.0f;
}

// Called when the game starts or when spawned
void ASpaceShip::BeginPlay()
{
	Super::BeginPlay();



}

// Called every frame
void ASpaceShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpaceShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &ASpaceShip::MoveForward);
}


void ASpaceShip::MoveForward(float value)
{
	FVector t_ForceToAdd = FVector(1, 0, 0) * MovementForce * value;

	Mesh->AddForce(t_ForceToAdd);
}

