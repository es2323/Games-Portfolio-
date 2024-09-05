// Fill out your copyright notice in the Description page of Project Settings.

#include "PeggleBlock.h"
#include "PaperSpriteComponent.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"


// Sets default values
APeggleBlock::APeggleBlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MySprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("My Image"));
	MySprite->OnComponentHit.AddDynamic(this,&APeggleBlock::OnHit);
	RootComponent = MySprite;
	

}

void APeggleBlock::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	MySprite->SetNotifyRigidBodyCollision(true);
	
}
// Called when the game starts or when spawned
void APeggleBlock::BeginPlay()
{
	Super::BeginPlay();
	
}

void APeggleBlock::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp,Warning,TEXT("Brick Hit attempting to destroy"));
	if (!DestroyTimer.IsValid())
	{
		GetWorld()->GetTimerManager().SetTimer(DestroyTimer,this,&APeggleBlock::DestroyThisObject,0.6,false);
	}
}

void APeggleBlock::DestroyThisObject()
{
	Destroy();
}


// Called every frame
void APeggleBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

