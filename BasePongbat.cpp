// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePongbat.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ABasePongbat::ABasePongbat()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MySprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("My Image"));
	RootComponent = MySprite; 
	MyCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("My HitBox"));
	MyCollider->SetBoxExtent(FVector(32,32,32));
	MyCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	MyCollider->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABasePongbat::BeginPlay()
{
	Super::BeginPlay();
	MyCollider->SetBoxExtent(MySprite->Bounds.GetBox().GetSize()/2);
	
}

// Called every frame
void ABasePongbat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasePongbat::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

