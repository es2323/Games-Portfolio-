// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Mario.generated.h"

UENUM()
enum class KnightAnimationState : uint8
{
	AS_WALKING_RIGHT,
	AS_WALKING_LEFT,
	AS_IDLE,
	AS_EMPTY,
	AS_DEAD,
};

UCLASS()
class MYPROJECT_API AMario : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMario();
	UPROPERTY(VisibleAnywhere,Category = "Sprites")
	class UPaperFlipbookComponent* MySprite;
	UPROPERTY(VisibleAnywhere, Category = "Collider")
	class UCapsuleComponent* MyBodyCollider;
	UPROPERTY(VisibleAnywhere, Category = "Camera Setup")
	class USpringArmComponent* MySpringArm;
	UPROPERTY(VisibleAnywhere, Category = "Camera Setup")
	class UCameraComponent* MyCamera;

	UPROPERTY(EditAnywhere, Category = "Player Properties")
	float JumpForce = 1000;
	UPROPERTY(EditAnywhere, Category = "Player Properties")
	float PlayerAcceleration = 1000;
	UPROPERTY(EditAnywhere, Category = "Player Properties")
	float PlayerMaxSpeed = 32;

	UPROPERTY(EditDefaultsOnly, Category = "Animations")
	class UPaperFlipbook* Flipbook_WalkingRight;
	UPROPERTY(EditDefaultsOnly, Category = "Animations")
	class UPaperFlipbook* Flipbook_Idle;

	UPROPERTY(VisibleAnywhere, Category = "Animations")
	KnightAnimationState CurrentAnimationState;
	UPROPERTY(VisibleAnywhere, Category = "Animations")
	KnightAnimationState OldAnimationState;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void MovePlayerHorizontal(float value);
	void Jump();
	void IdentifyAnimStates();
	void ProcessAnimStateMachine();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void OnCollision(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                 FVector NormalImpulse, const FHitResult& Hit);
	void KillMario();
};
