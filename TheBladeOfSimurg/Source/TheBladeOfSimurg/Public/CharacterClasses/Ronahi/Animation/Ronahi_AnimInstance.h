// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterClasses/Ronahi/Types/RonahiCharacterTypes.h"
#include "Ronahi_AnimInstance.generated.h"

/**
 * 
 */

class ARonahiCharacter;
class UCharacterMovementComponent;

UCLASS()
class THEBLADEOFSIMURG_API URonahi_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()


public:

	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, Category = "Acho AnimInstance")
	TObjectPtr<ARonahiCharacter>RonahiCharacter;


	UPROPERTY(BlueprintReadOnly, Category = Movement)
	TObjectPtr<UCharacterMovementComponent>RonahiCharacterMovement;

	UPROPERTY(BlueprintReadWrite, Category = Movement)
	float GroundSpeed;

	UPROPERTY(BlueprintReadWrite, Category = Movement)
	bool IsFalling;

	UPROPERTY(BlueprintReadWrite, Category = Movement)
	FVector Velocity;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	ERonahiCharacterState RonahiCharacterState;
	
};
