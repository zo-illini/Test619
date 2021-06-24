
// Fill out your copyright notice in the Description page of Project Settings.


#include "MySkeletalMeshComponent.h"

void UMySkeletalMeshComponent::BeginPlay()
{
	Super::BeginPlay();

	if (this->GetOwner()->GetAttachParentActor() != VehicleActor)
	{
		this->GetOwner()->AttachToActor(VehicleActor, FAttachmentTransformRules::KeepWorldTransform);
	}

	check(VehicleActor);
	VehicleComponent = Cast<UPrimitiveComponent>(VehicleActor->GetComponentsByTag(UPrimitiveComponent::StaticClass(), FName("Vehicle"))[0]);

	check(VehicleComponent)

	HasBegunPlay = true;
}

void UMySkeletalMeshComponent::CompleteParallelAnimationEvaluation(bool bDoPostAnimEvaluation)
{
	Super::CompleteParallelAnimationEvaluation(bDoPostAnimEvaluation);

	if (HasBegunPlay)
	{
		const UPhysicsAsset* const PhysicsAsset = GetPhysicsAsset();

		for (int32 i = 0; i < Bodies.Num(); i++)
		{
			FBodyInstance* BodyInst = Bodies[i];
			if (!ensure(BodyInst))
			{
				continue;
			}
			//if (BodyInst->IsInstanceSimulatingPhysics())
			if (PhysicsAsset->SkeletalBodySetups.IsValidIndex(i) && !IsSimulatingPhysics(PhysicsAsset->SkeletalBodySetups[i]->BoneName))
			{

				FTransform NewTransform = BodyInst->GetUnrealWorldTransform();
				NewTransform.AddToTranslation(VehicleComponent->GetPhysicsLinearVelocity() * GetWorld()->GetDeltaSeconds());
				BodyInst->SetBodyTransform(NewTransform, ETeleportType::None);
			}
		}
	}
}
