// Fill out your copyright notice in the Description page of Project Settings.


#include "BreakoutBall.h"
#include "PaperSpriteComponent.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "BreakoutBat.h"
#include "BreakoutBrick.h"
#include "Math/Vector.h"

// Sets default values
ABreakoutBall::ABreakoutBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MySprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("My Image"));
	RootComponent = MySprite;
	MyCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("My HitBox"));
	MyCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	MyCollider->SetupAttachment(RootComponent);

	MinX = -2048.0f; // Adjust based on your game's screen size
	MaxX = 2048.0f; // Adjust based on your game's screen size
}

// Called when the game starts or when spawned
void ABreakoutBall::BeginPlay()
{
	Super::BeginPlay();
	BallHalfWidth = MySprite->Bounds.GetBox().GetSize().X / 2;
	MyCollider->SetBoxExtent(FVector(BallHalfWidth,BallHalfWidth,BallHalfWidth));

	MyVelocity = FVector(300,0,300);

	AActor* GameCamera = UGameplayStatics::GetActorOfClass(GetWorld(),ACameraActor::StaticClass());
	UCameraComponent* GameCameraComponent = Cast<ACameraActor>(GameCamera)->GetCameraComponent();
	HalfPlayFieldHeight = (GameCameraComponent->OrthoWidth / GameCameraComponent->AspectRatio) / 2;
	HalfPlayFieldWidth = (GameCameraComponent->OrthoWidth / 2);

	
	BallSpeed = 300;

	MyCollider->OnComponentBeginOverlap.AddDynamic(this, &ABreakoutBall::OnCollision);
	
	
}

// Called every frame
void ABreakoutBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector MyUpdatedLocation = GetActorLocation()+(MyVelocity*DeltaTime);

	if (MyUpdatedLocation.Z + BallHalfWidth > HalfPlayFieldHeight)
	{
		MyVelocity.Z = -BallSpeed;
	}
	else if (MyUpdatedLocation.Z - BallHalfWidth < -HalfPlayFieldHeight)
	{
		MyVelocity.Z = BallSpeed;
		MyUpdatedLocation = FVector(0,0,0);
	}
	if(MyUpdatedLocation.X + BallHalfWidth > HalfPlayFieldWidth)
	{
		MyVelocity.X = -BallSpeed;
		
	}	
	else if(MyUpdatedLocation.X - BallHalfWidth < -HalfPlayFieldWidth)
	{
		MyVelocity.X = BallSpeed;
	}
	ResetIfOutOfBounds();
	SetActorLocation(MyUpdatedLocation);
};

void ABreakoutBall::ResetIfOutOfBounds()
{
	FVector CurrentPosition = GetActorLocation();
	if (CurrentPosition.X < MinX || CurrentPosition.X > MaxX)
	{
		// Reset ball position to the center of the screen
		SetActorLocation(FVector::ZeroVector);
	}
}
void ABreakoutBall::OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)

{
	if (OtherActor->IsA(ABreakoutBat::StaticClass()))
	{
		UE_LOG(LogTemp,Warning,TEXT("I have smashed something!"));
		FVector BallPosition = GetActorLocation();
		MyVelocity.Z = BallSpeed;
	}
	else if (OtherActor->IsA(ABreakoutBrick::StaticClass()))
	{
		UE_LOG(LogTemp, Warning, TEXT("I HIT A BRICK"));
		OtherActor->Destroy();
	}
	HitDirection = GetActorLocation() - OtherActor->GetActorLocation();
	HitDirection.Normalize();
	if (abs(HitDirection.X) > abs(HitDirection.Z))
	{
		if (HitDirection.X > 0)
		{
			MyVelocity.X = BallSpeed;
		}
		else if (HitDirection.X < 0)
		{
			MyVelocity.X = -BallSpeed;
		}
		
	}
	else
	{
		if (HitDirection.Z > 0)
		{
			MyVelocity.Z = BallSpeed;
		}
		else if (HitDirection.Z < 0)
		{
			MyVelocity.Z = -BallSpeed;
		}
	}
}
	