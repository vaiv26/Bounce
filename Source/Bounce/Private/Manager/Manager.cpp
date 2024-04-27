// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/Manager.h"

// Sets default values
AManager::AManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	//Initialising values
	totalCollection.Add("Green",12);
	totalCollection.Add("Red",6);
	totalCollection.Add("Black", 1);
	
	ratioOfCollection.Add("Green",6);
	ratioOfCollection.Add("Red",3);
	ratioOfCollection.Add("Black", 1);

}

// TODO: Make a Spawn function which will handle spawning of balls.
AActor* AManager::SpawningBalls(FVector location,UClass* BallToSpawn)
{
	UWorld* World = GetWorld();
	FRotator SpawnRotation = FRotator::ZeroRotator;

	FActorSpawnParameters ActorSpawnParameters;
	ActorSpawnParameters.Owner = this;
	AActor* SpawnedActor = World->SpawnActor<AActor>(BallToSpawn, location, SpawnRotation, ActorSpawnParameters);
	return SpawnedActor;
}

// Called when the game starts or when spawned
void AManager::BeginPlay()
{
	Super::BeginPlay();
	// Ratio has to be maintained as in the dictionary in the initial start of the game
	// the Ratio has to same throughout the game
	// TODO:Make a Spawn function for initial Spawning;
}


// Called every frame
void AManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int AManager::RandomNumberInRange(int minValue, int MaxValue)
{
	if(minValue > MaxValue)
	{
		int temp = minValue;
		minValue = MaxValue;
		MaxValue = temp;
	}

	return FMath::RandRange(minValue,MaxValue);
}

