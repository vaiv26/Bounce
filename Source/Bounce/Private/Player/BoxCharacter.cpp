
// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/BoxCharacter.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABoxCharacter::ABoxCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABoxCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoxCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABoxCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump" , IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis("MoveRight" , this, &ABoxCharacter::MoveRight);
	

}

void ABoxCharacter::DamageInterface(AActor* DamagedActor, int Points)
{
	PlayerScore = PlayerScore + Points;
	SendInfoToManager(DamagedActor);
	
}

void ABoxCharacter::MoveRight(float InputValue)
{
	FVector RightDirection = GetActorRightVector();
	AddMovementInput(RightDirection,InputValue);
}

