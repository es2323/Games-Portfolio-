#include "PeggleBallLauncher.h"
#include "PaperSpriteComponent.h"
#include "Math/UnitConversion.h"
#include "Components/BoxComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h" // Include necessary header for InputComponent

// Sets default values
APeggleBallLauncher::APeggleBallLauncher()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MySprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("MyImage"));
	RootComponent = MySprite;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}


void APeggleBallLauncher::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	MySprite->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MySprite->TranslucencySortPriority = 3;
}


void APeggleBallLauncher::MovePlayer(float input)
{
	SetActorRotation(GetActorRotation() + FRotator(1*input, 0, 0));
}
void APeggleBallLauncher::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Firing!"));
	AActor* SpawnedBall = GetWorld()->SpawnActor<AActor>(BallBPClass, GetActorLocation(), GetActorRotation());
	FVector ShotDirection = GetActorUpVector()*= -1;
	SpawnedBall->GetComponentByClass<UPaperSpriteComponent>()->AddImpulse(ShotDirection * ShotPower); 
}

void APeggleBallLauncher::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Bind input actions here
	InputComponent->BindAxis("Horizontal", this, &APeggleBallLauncher::MovePlayer);
	InputComponent->BindAction("Fire", IE_Pressed, this, &APeggleBallLauncher::Fire);
}


// Called when the game starts or when spawned
void APeggleBallLauncher::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APeggleBallLauncher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
