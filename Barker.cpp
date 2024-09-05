// Fill out your copyright notice in the Description page of Project Settings.


#include "Barker.h"

// Sets default values
ABarker::ABarker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABarker::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABarker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp,Log,TEXT("Hello Unreal"));


}

