// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "ShooterAssetPack/PawnsCharacters/ShooterCharacter.h"


UBTTask_Shoot::UBTTask_Shoot() 
{
    NodeName = "Shoot";
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if(OwnerComp.GetAIOwner() == nullptr) // Checking for null pointer
    {
        return EBTNodeResult::Failed;
    }
    AShooterCharacter* Character = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn()); // Casting AShooterCharacter
    if(Character == nullptr) // Checking for null pointer
    {
        return EBTNodeResult::Failed;
    }
    Character->Shoot();
    return EBTNodeResult::Succeeded;
}
