// Fill out your copyright notice in the Description page of Project Settings.


#include "Balls/Balls.h"
#include "Manager/Manager.h"

// Sets default values
ABalls::ABalls()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ballMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	ballMesh->SetupAttachment(RootComponent);
	SetRootComponent(ballMesh);

	ballMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	ballMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	ballMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn,ECR_Overlap);
	ballMesh->SetCollisionResponseToChannel(ECC_WorldStatic,ECR_Block);
}

// Called when the game starts or when spawned
void ABalls::BeginPlay()
{
	Super::BeginPlay();
	ballMesh->OnComponentBeginOverlap.AddDynamic(this, &ABalls::OnSphereOverlap);
}

void ABalls::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepHitResult)
{
	// Delete the Object, Call the Game Manager to Set points and maintain the ratio
	int score = 0;
	if(PointsTable[FMath::RandRange(0,PointsTable.Num() - 1)])
	{
		score = PointsTable[FMath::RandRange(0,PointsTable.Num() - 1)];
	}
	ICollisionInterface* Interface = Cast<ICollisionInterface>(OtherActor);
	if(Interface)
	{
		AActor* OverlappedActor = OverlappedComponent->GetOwner();
		if(OverlappedActor)
		{
			Interface->DamageInterface(OverlappedActor, score);
			
			OverlappedActor->SetLifeSpan(0.5f);
			//Play Animation
			//Play Sound
			
		}
	}
}

// Called every frame
void ABalls::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

