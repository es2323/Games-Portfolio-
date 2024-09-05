// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPongBat.h"
#include "Math/UnitConversion.h"

void APlayerPongBat::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	InputComponent->BindAxis("Vertical", this, &APlayerPongBat::MovePlayer);
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APlayerPongBat::MovePlayer(float input)
{	FVector CurrentPosition = GetActorLocation();
	FVector NewPosition = CurrentPosition + FVector(0,0,4*input);
	float MinY = -900 / 2.0f + 100 / 2.0f; // Adjust if needed
	float MaxY = 900 / 2.0f - 100 / 2.0f; // Adjust if needed

	// Clamp the new position to stay within screen boundaries
	NewPosition.Z = FMath::Clamp(NewPosition.Z, MinY, MaxY);

	// Set the new position
	SetActorLocation(NewPosition);
}
