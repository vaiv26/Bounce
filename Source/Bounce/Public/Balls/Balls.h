// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollisionInterface.h"
#include "GameFramework/Actor.h"
#include "Manager/Manager.h"
#include "Balls.generated.h"

UCLASS()
class BOUNCE_API ABalls : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABalls();

	UPROPERTY(EditAnywhere, Category="Score")
	TArray<int> PointsTable;

	UPROPERTY(EditAnywhere, Category="Point")
	int BallPoint = 0;

	UPROPERTY(EditAnywhere, Category="JumpPoint")
	float jumpPoint = 180.0f;

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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void InformActor(AActor* OverlappingActor);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void StartBouncing();

	UFUNCTION(BlueprintCallable,Category="GetterFunction")
	int GetSpawnPoint(){return spawnPoint;}
	UFUNCTION(BlueprintCallable,Category="GetterFunction")
	FString GetActorName(){return ActorName;}

	UFUNCTION(BlueprintCallable,Category="SetterFunction")
	void SetspawnPoint(int point){spawnPoint = point;}
	UFUNCTION(BlueprintCallable,Category="SetterFunction")
	void SetActorName(FString name){ ActorName = name;}

	UFUNCTION(BlueprintCallable, Category="SizeChange")
	UStaticMeshComponent* GetBallMesh(){return ballMesh;}

	UFUNCTION(BlueprintCallable, Category="BallPoint")
	int GetBallPoint(){ return BallPoint;}
	UFUNCTION(BlueprintCallable, Category="BallPoint")
	void SetBallPoint(int point){BallPoint = point;}

	UFUNCTION(BlueprintCallable, Category="JumpPoint")
	float GetJumpPoint(){return jumpPoint;}
	UFUNCTION(BlueprintCallable, Category="JumpPoint")
	void SetJumpPoint(float jump){ jumpPoint = jump;}



};
