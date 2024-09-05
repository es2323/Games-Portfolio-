// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"
#include "BreakoutBall.generated.h"


UCLASS()
class MYPROJECT_API ABreakoutBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABreakoutBall();
	UPROPERTY(VisibleAnywhere,Category = "My Sprite")
	UPaperSpriteComponent* MySprite;

	UPROPERTY(VisibleAnywhere,Category = "My Collider")
	UBoxComponent* MyCollider;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Bat")
	FVector HitDirection;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float BallHalfWidth;
	float BallSpeed;
	 

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
