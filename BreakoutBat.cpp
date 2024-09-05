// Fill out your copyright notice in the Description page of Project Settings.

#include "BreakoutBat.h"
#include "Math/UnitConversion.h"

void ABreakoutBat::MovePlayer(float input)
{
	SetActorLocation(GetActorLocation()+FVector(4*input,0,0));
}

void ABreakoutBat::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Bind the "Horizontal" axis input to the MovePlayer function
	PlayerInputComponent->BindAxis("Horizontal", this, &ABreakoutBat::MovePlayer);
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}
