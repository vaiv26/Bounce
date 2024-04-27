// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollisionInterface.h"
#include "GameFramework/Actor.h"
#include "Manager/Manager.h"
#include "Balls.generated.h"

UENUM(BlueprintType)
enum class EBallState: uint8
{
	EBS_Initial UMETA(DisplayName =  "Initial State"),
	EBS_Explode UMETA(DisplayName = "Explode"),

	EBS_Max UMETA(DisplayName = " DefaultMax")
};

UCLASS()
class BOUNCE_API ABalls : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABalls();

	UPROPERTY(EditAnywhere, Category="Score")
	TArray<int> PointsTable;

	UPROPERTY(EditAnywhere, Category="SpawnPoint")
	int spawnPoint;

	UPROPERTY(EditAnywhere, Category="Name")
	FString ActorName;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnSphereOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepHitResult
		) ;

private:
	UPROPERTY(VisibleAnywhere, Category = "ball Properties")
	UStaticMeshComponent* ballMesh;

	UPROPERTY(VisibleAnywhere)
	EBallState BallState;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void InformActor(AActor* OverlappingActor);

	UFUNCTION(BlueprintCallable,Category="GetterFunction")
	int GetSpawnPoint(){return spawnPoint;}
	UFUNCTION(BlueprintCallable,Category="GetterFunction")
	FString GetActorName(){return ActorName;}

	UFUNCTION(BlueprintCallable,Category="SetterFunction")
	void SetspawnPoint(int point){spawnPoint = point;}
	UFUNCTION(BlueprintCallable,Category="SetterFunction")
	void SetActorName(FString name){ ActorName = name;}

};
