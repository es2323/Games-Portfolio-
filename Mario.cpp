// Fill out your copyright notice in the Description page of Project Settings.

#include "Mario.h"
#include "Spike.h"
#include "PaperFlipbookComponent.h"
#include "PaperSpriteComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AMario::AMario()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MySprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("MarioBodySprite"));
	MyBodyCollider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("MarioBodyCapsule"));
	MySpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("MarioSpringArm"));
	MyCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MarioBodyCamera"));
	RootComponent = MyBodyCollider;
	MySprite->SetupAttachment((RootComponent));
	MySpringArm->SetupAttachment((RootComponent));
	MyCamera->SetupAttachment(MySpringArm);
	
}

// Called when the game starts or when spawned
void AMario::BeginPlay()
{
	Super::BeginPlay();
	CurrentAnimationState = KnightAnimationState::AS_IDLE;
	OldAnimationState = KnightAnimationState::AS_EMPTY;
	ProcessAnimStateMachine();
}

void AMario::MovePlayerHorizontal(float value)
{
	MyBodyCollider->AddForce(FVector(4, 0, 0)*value*PlayerAcceleration, NAME_None, true);
}

void AMario::Jump()
{
	MyBodyCollider->AddImpulse(FVector(0, 0, 1)*JumpForce);
}

void AMario::IdentifyAnimStates()
{
	OldAnimationState = CurrentAnimationState;

	float CurrentSpeed = MyBodyCollider->GetPhysicsLinearVelocity().X;
	if(CurrentSpeed > 5)
	{
		CurrentAnimationState = KnightAnimationState::AS_WALKING_RIGHT;
	}
	else if (CurrentSpeed < -5)
	{
		CurrentAnimationState = KnightAnimationState::AS_WALKING_LEFT;
	}
	else
	{
		CurrentAnimationState = KnightAnimationState::AS_IDLE;
	}
}

void AMario::ProcessAnimStateMachine()
{
	if (CurrentAnimationState == OldAnimationState)
	{
		return;
	}

	switch (CurrentAnimationState)
	{
	case KnightAnimationState::AS_IDLE:
		{
			MySprite->SetFlipbook(Flipbook_Idle);
			break;
		}
	case KnightAnimationState::AS_WALKING_RIGHT:
		{
			MySprite->SetFlipbook(Flipbook_WalkingRight);
			MySprite->SetRelativeRotation(FRotator(0,0,0));
			break;
		}
	case KnightAnimationState::AS_WALKING_LEFT:
		{
			MySprite->SetFlipbook(Flipbook_WalkingRight);
			MySprite->SetRelativeRotation(FRotator(0,180, 0));
			break;
		}
	case KnightAnimationState::AS_DEAD:
		{
			UGameplayStatics::OpenLevel(GetWorld(),"L_GameOver");
			break; 
		}
	}
}


// Called every frame
void AMario::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector ClampSpeed = MyBodyCollider->GetPhysicsLinearVelocity();
	ClampSpeed.X = FMath::Clamp(ClampSpeed.X, -PlayerMaxSpeed, PlayerMaxSpeed );
	MyBodyCollider->SetPhysicsLinearVelocity((ClampSpeed));
	
	IdentifyAnimStates();
	ProcessAnimStateMachine();
}

// Called to bind functionality to input
void AMario::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("Horizontal", this, &AMario::MovePlayerHorizontal);
	InputComponent->BindAction("Fire", IE_Pressed, this, &AMario::Jump);

}

void AMario::OnCollision(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->Tags.Contains("Floor"))
	{
		bool bIsJumping = false; 
	}
}

void AMario::KillMario()
{
	UE_LOG(LogTemp, Warning, TEXT("Mario's Dead"));
	CurrentAnimationState = KnightAnimationState::AS_DEAD;
	ProcessAnimStateMachine();
}