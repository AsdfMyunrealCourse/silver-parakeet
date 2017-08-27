// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrolingGuard.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API APatrolingGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()

		UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
		TArray<AActor*> PatrolPoints;
	
	
};
