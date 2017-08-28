// Fill out your copyright notice in the Description page of Project Settings.

#include "FPS.h"
#include "PatrolRoute.h"

TArray<AActor*> UPatrolRoute::GetPatrolPoints() const
{
	return PatrolPoints;
}