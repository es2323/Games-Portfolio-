// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePongbat.h"
#include "Math/Vector.h"
#include "BreakoutBat.generated.h"


/**
 * 
 */
UCLASS()
class MYPROJECT_API ABreakoutBat : public ABasePongbat
{
	GENERATED_BODY()
public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MovePlayer(float input);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Bat")
	FVector HitDirection;
	
};
