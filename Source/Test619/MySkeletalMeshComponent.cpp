
// Fill out your copyright notice in the Description page of Project Settings.


#include "MySkeletalMeshComponent.h"

void UMySkeletalMeshComponent::BeginPlay()
{
	Super::BeginPlay();

	//this->SetSimulatePhysics(true);
	//this->SetEnableGravity(false);
	//this->SetAllBodiesBelowPhysicsBlendWeight("thigh_l", LowerBodyPhysicsBlendWeight);
	//this->SetAllBodiesBelowPhysicsBlendWeight("thigh_r", LowerBodyPhysicsBlendWeight);
	//this->SetAllBodiesBelowPhysicsBlendWeight("spine_01", UpperBodyPhysicsBlendWeight);

	//this->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	//this->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	if (this->GetOwner()->GetAttachParentActor() != VehicleActor)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Warning: MySkeletalMeshComponent's owner is not attached to its assigned vehicle's owner."));
		this->GetOwner()->AttachToActor(VehicleActor, FAttachmentTransformRules::KeepWorldTransform);
	}

	check(VehicleActor);

	VehicleComponent = Cast<UPrimitiveComponent>(VehicleActor->GetComponentsByTag(UPrimitiveComponent::StaticClass(), FName("Vehicle"))[0]);

	check(VehicleComponent)

	RelativeLocationToVehicle = GetRelativeLocation();

	HasBegunPlay = true;
}


void UMySkeletalMeshComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (HasBegunPlay)
		AddWorldOffset(VehicleComponent->GetPhysicsLinearVelocity() * GetWorld()->DeltaTimeSeconds);
}

void UMySkeletalMeshComponent::OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport)
{
	Super::OnUpdateTransform(UpdateTransformFlags, Teleport);

	if (HasBegunPlay && UpdateTransformFlags == EUpdateTransformFlags::PropagateFromParent)
	{
		SetRelativeLocation(RelativeLocationToVehicle);
		//DebugDistance = VehicleComponent->GetComponentTransform().InverseTransformPosition(GetComponentLocation());
	}

}
