// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"
#include "PongBall.generated.h"


UCLASS()
class MYPROJECT_API APongBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APongBall();
	UPROPERTY(VisibleAnywhere,Category = "My Sprite")
	UPaperSpriteComponent* MySprite;

	UPROPERTY(VisibleAnywhere,Category = "My Collider")
	UBoxComponent* MyCollider;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	 

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void OnCollision(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult); 
	void ResetIfOutOfBounds();
	
private:
	FVector MyVelocity;
	float HalfPlayFieldHeight;
	float HalfPlayFieldWidth;

	float MinX;
	float MaxX;
};
