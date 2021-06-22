// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "MySkeletalMeshComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TEST619_API UMySkeletalMeshComponent : public USkeletalMeshComponent
{
	GENERATED_BODY()

	public:
		virtual void BeginPlay() override;
		virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		virtual void OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport = ETeleportType::None) override;

	UPROPERTY(EditAnywhere)
		UPrimitiveComponent* Vehicle;
	
	UPROPERTY(VisibleAnywhere)
		FVector RelativeLocationToVehicle;


};
