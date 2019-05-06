// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AIController can't find player tank."))
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s."), *(PlayerTank->GetName()))
	}
}

ATank * ATankAIController::GetPlayerTank() const
{
	//GetWorld()->GetFirstPlayerController()
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);
}