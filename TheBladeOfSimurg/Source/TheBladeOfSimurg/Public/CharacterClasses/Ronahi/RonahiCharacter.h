// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterClasses/TBOS_CharacterBase.h"
#include "CharacterClasses/Ronahi/Types/RonahiCharacterTypes.h"
#include "RonahiCharacter.generated.h"

/**
 * 
 */
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class THEBLADEOFSIMURG_API ARonahiCharacter : public ATBOS_CharacterBase
{
	GENERATED_BODY()
	
public:

	ARonahiCharacter();


	FORCEINLINE ERonahiCharacterState GetCharacterState() const { return RonahiCharacterState; }

protected:

	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;


	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> CameraSpringArm;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> Camera;

	// Input Map
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> Default_RonahiIMC;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> RonahiMoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> RonahiLookAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> RonahiJumpAction;

	// Event Functions
	void RonahiMove(const FInputActionValue& Value);
	void RonahiLook(const FInputActionValue& Value);


private:

	ERonahiCharacterState RonahiCharacterState = ERonahiCharacterState::ERCS_UnEquiped;
};
