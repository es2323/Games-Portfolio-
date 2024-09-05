// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteComponent.h"
#include "GameFramework/Pawn.h"
#include "Components/BoxComponent.h"
#include "BasePongbat.generated.h"

UCLASS()
class MYPROJECT_API ABasePongbat : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePongbat();

	UPROPERTY(VisibleAnywhere,Category = "My Collider")
	UBoxComponent* MyCollider; 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Sprites")
	class UPaperSpriteComponent* MySprite; 

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
