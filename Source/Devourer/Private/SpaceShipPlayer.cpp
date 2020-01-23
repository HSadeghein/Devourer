// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceShipPlayer.h"
#include "Components/InputComponent.h"

// Sets default values
ASpaceShipPlayer::ASpaceShipPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("root"));
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh"));
	mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASpaceShipPlayer::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASpaceShipPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpaceShipPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this,&ASpaceShipPlayer::MoveForward);


}

void ASpaceShipPlayer::MoveForward(float axisValue) {
	_velocity.X = FMath::Clamp(axisValue, -1.0f,1.0f)*100.0f;
}