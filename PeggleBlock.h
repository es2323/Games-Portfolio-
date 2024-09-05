// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "PeggleBlock.generated.h"

UCLASS()
class MYPROJECT_API APeggleBlock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APeggleBlock();
	
	
	UPROPERTY(VisibleAnywhere, Category = "Sprites")
	class UPaperSpriteComponent* MySprite;

	UPROPERTY(VisibleAnywhere,Category = "My Collider")
	UBoxComponent* MyCollider;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent , AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	UFUNCTION()
	virtual void OnConstruction(const FTransform& Transform) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime);
	FTimerHandle DestroyTimer;
	void DestroyThisObject();

};
