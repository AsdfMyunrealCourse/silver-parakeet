// Fill out your copyright notice in the Description page of Project Settings.

#include "FPS.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"
#include "ChooseNextWaypoint.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{

	

	//Get Patrol Route
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass <UPatrolRoute>();
	
	if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }

	auto PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("A guard is missing patrol points"));
		return EBTNodeResult::Failed;
	}
	//Set next waypoint
	auto BlackBoardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackBoardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackBoardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	//Cycle Index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackBoardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	//UE_LOG(LogTemp, Warning, TEXT("Waypoint Index: %i"), Index)
	return EBTNodeResult::Succeeded;


}
