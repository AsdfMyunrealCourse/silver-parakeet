// Fill out your copyright notice in the Description page of Project Settings.

#include "FPS.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolingGuard.h" //TODO remove Coupling
#include "ChooseNextWaypoint.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	//TODO protect against empty patrol routes
	//Get Patrol Points
	auto AIController=OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrolingGuard = Cast<APatrolingGuard>(ControlledPawn);
	auto PatrolPoints = PatrolingGuard->PatrolPoints;
	
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
