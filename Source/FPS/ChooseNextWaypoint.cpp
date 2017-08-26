// Fill out your copyright notice in the Description page of Project Settings.

#include "FPS.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ChooseNextWaypoint.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	auto BlackBoardComp = OwnerComp.GetBlackboardComponent();

	auto Index = BlackBoardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	UE_LOG(LogTemp, Warning, TEXT("Waypoint Index: %i"), Index)
	return EBTNodeResult::Succeeded;
}
