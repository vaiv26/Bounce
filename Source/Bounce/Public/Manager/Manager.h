// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Manager.generated.h"

UENUM(BlueprintType)
enum class EBallState: uint8
{
	EBS_Initial UMETA(DisplayName =  "Initial State"),
	EBS_Explode UMETA(DisplayName = "Balck Ball Explode"),

	EBS_Max UMETA(DisplayName = " DefaultMax")
};

UCLASS()
class BOUNCE_API AManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AManager();

private:
	
	// Total Collection of balls
	UPROPERTY(EditAnywhere)
	TMap<FString, int> totalCollection;

	//Ratio which needs to be maintained on screen
	UPROPERTY(EditAnywhere)
	TMap<FString, int> ratioOfCollection;

public:

	UFUNCTION(BlueprintCallable, Category="ManagerFunctions")
	int RandomNumberInRange(int minValue, int MaxValue);
	
	UFUNCTION(BlueprintCallable, Category="ManagerFunctions")
	AActor* SpawningBalls(FVector location, UClass* BallToSpawn);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="ManagerFunctions")
	void SpawnInitialBalls();

	UFUNCTION(BlueprintCallable, Category = "TMapAccess")
	TMap<FString, int >& GetMyMap() {return ratioOfCollection;}

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void GetCollisionInformation(AActor* OverlappedActor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

};
