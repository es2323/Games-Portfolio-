// Fill out your copyright notice in the Description page of Project Settings.


#include "Deathblock.h"
#include "Mario.h"
#include "PaperSpriteComponent.h"

// Sets default values
ADeathblock::ADeathblock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MySprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("MyImage"));
	RootComponent = MySprite;
	MySprite->OnComponentHit.AddDynamic(this, &ADeathblock::OnCollision);

}

// Called when the game starts or when spawned
void ADeathblock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADeathblock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADeathblock::OnCollision(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->IsA(AMario::StaticClass()))
	{
		Cast<AMario>(OtherActor)->KillMario(); 
	}
}
