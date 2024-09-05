// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePongbat.h"
#include "PlayerPongBat.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API APlayerPongBat : public ABasePongbat
{
	GENERATED_BODY()
public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MovePlayer(float input);
	
};
