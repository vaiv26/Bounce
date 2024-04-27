// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CollisionInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCollisionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOUNCE_API ICollisionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION()
	virtual void DamageInterface(AActor* DamagedActor, int Points) = 0;

	
};
