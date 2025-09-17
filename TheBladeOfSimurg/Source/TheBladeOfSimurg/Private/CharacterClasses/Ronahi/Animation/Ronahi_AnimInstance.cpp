// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterClasses/Ronahi/Animation/Ronahi_AnimInstance.h"

#include "CharacterClasses/Ronahi/RonahiCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"


void URonahi_AnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	RonahiCharacter = Cast<ARonahiCharacter>(TryGetPawnOwner());

	if (RonahiCharacter)
	{
		RonahiCharacterMovement = RonahiCharacter->GetCharacterMovement();
	}

}

void URonahi_AnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (RonahiCharacterMovement)
	{
		Velocity = RonahiCharacterMovement->Velocity;
		GroundSpeed = UKismetMathLibrary::VSizeXY(RonahiCharacterMovement->Velocity);
		IsFalling = RonahiCharacterMovement->IsFalling();
		RonahiCharacterState = RonahiCharacter->GetCharacterState();
	}
}
