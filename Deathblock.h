// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Deathblock.generated.h"

UCLASS()
class MYPROJECT_API ADeathblock : public AActor
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	void OnCollision(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	// Sets default values for this actor's properties
	ADeathblock();
	UPROPERTY(VisibleAnywhere,Category = "Sprites")
	class UPaperSpriteComponent* MySprite;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
