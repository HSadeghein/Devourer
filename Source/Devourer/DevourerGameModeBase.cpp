// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "DevourerGameModeBase.h"
#include"SpaceshipPlayerController.h"
#include "SpaceShip.h" 

ADevourerGameModeBase::ADevourerGameModeBase(const class FObjectInitializer& objectInitializer) :Super(objectInitializer) {
	PlayerControllerClass = ASpaceshipPlayerController::StaticClass();
	DefaultPawnClass = ASpaceShip::StaticClass();
}

