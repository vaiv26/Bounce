// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollisionInterface.h"
#include "GameFramework/Character.h"
#include "Manager/Manager.h"
#include "BoxCharacter.generated.h"

UCLASS()
class BOUNCE_API ABoxCharacter : public ACharacter, public ICollisionInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABoxCharacter();
	UPROPERTY(EditAnywhere, Category="Score")
	int PlayerScore = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveRight(float InputValue);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void DamageInterface(AActor* DamagedActor, int Points) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SendInfoToManager(AActor* DamagedActor);

};
