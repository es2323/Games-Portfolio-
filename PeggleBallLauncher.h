#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PeggleBallLauncher.generated.h"

UCLASS()
class MYPROJECT_API APeggleBallLauncher : public APawn
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "Sprites")
	class UPaperSpriteComponent* MySprite;

	UPROPERTY(EditDefaultsOnly, Category = "Ammo")
	TSubclassOf<AActor> BallBPClass;

	UPROPERTY(EditAnywhere, Category = "Item Properties")
	float ShotPower = 10;


	
public:
	// Sets default values for this actor's properties
	APeggleBallLauncher();

	void MovePlayer(float input);
	void Fire();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Bat")
	FVector HitDirection;

	UPROPERTY(EditAnywhere, Category = "Ammo")
	UObject* Ball;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
