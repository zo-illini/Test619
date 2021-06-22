// Fill out your copyright notice in the Description page of Project Settings.


#include "MySkeletalMeshComponent.h"

void UMySkeletalMeshComponent::BeginPlay()
{
	Super::BeginPlay();
	if (Vehicle == nullptr) 
	{
		Vehicle = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	}

	if (Vehicle != nullptr) 
	{
		RelativeLocationToVehicle = GetRelativeLocation();
	}
}


void UMySkeletalMeshComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) 
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AddWorldOffset(Vehicle->GetPhysicsLinearVelocity() * GetWorld()->DeltaTimeSeconds);
}

void UMySkeletalMeshComponent::OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport)
{
	Super::OnUpdateTransform(UpdateTransformFlags, Teleport);
	if (Vehicle != nullptr &&  UpdateTransformFlags == EUpdateTransformFlags::PropagateFromParent) 
	{
		SetRelativeLocation(RelativeLocationToVehicle);
	}
}
