// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceShip.h"
#include "Components/InputComponent.h"
#include "SpaceshipPlayerController.h"
#include "Math/Box.h"
#include "Components/BoxComponent.h"

// Sets default values
ASpaceShip::ASpaceShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	//Initialize The Componenets
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("box collider"));

	//Set The Hirarchy
	RootComponent = Mesh;
	SpringArm->SetupAttachment(Mesh);
	/*SpringArm->SetUsingAbsoluteRotation(true);
	SpringArm->SetRelativeLocation(FVector(16.0f, 0.0f, 47.0f));
	auto q = FQuat::MakeFromEuler(FVector(0,-20,0));
	
	SpringArm->SetWorldRotation(q);*/
	Camera->SetupAttachment(SpringArm);
	BoxCollider->SetupAttachment(Mesh);
	BoxCollider->SetRelativeLocation(FVector(2200.0f, 0.0f, 300.0f));
	BoxCollider->SetRelativeScale3D(FVector(30.0f,18.5f,11.5f));

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	//Set physics
	Mesh->SetSimulatePhysics(true);
	Mesh->SetEnableGravity(false);
	//Mesh->SetLinearDamping(0);
	//Mesh->SetAngularDamping(.5f);
	
	MovementForce = 10000.0f;
}

// Called when the game starts or when spawned
void ASpaceShip::BeginPlay()
{
	Super::BeginPlay();
	auto controller = GetWorld()->GetFirstPlayerController();
	controller->Possess(this);


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

	//InputComponent->BindAxis("MoveForward", this, &ASpaceShip::MoveForward);
	InputComponent->BindAction("SpawnEnemy", IE_Released, this, &ASpaceShip::SpawnEnemy);
}

void ASpaceShip::PossessedBy(AController* controller) {
	Super::PossessedBy(controller);
	Controller = controller;

	auto rotator = Mesh->GetRelativeRotation();
	// Add force
	FVector force = Mesh->GetForwardVector() * MovementForce;
	Mesh->AddForce(force);
}


void ASpaceShip::MoveForward(float value)
{
	FVector t_ForceToAdd = FVector(1, 0, 0) * MovementForce * value;

	Mesh->AddForce(t_ForceToAdd);
}

void ASpaceShip::SpawnEnemy()
{
	auto world = GetWorld();

	if (world != nullptr) {
		auto pos = Mesh->GetRelativeLocation();
		pos += (Mesh->GetForwardVector()*1000.0f);
	
		world->SpawnActor(enemyPawn, &pos);
	}
}

