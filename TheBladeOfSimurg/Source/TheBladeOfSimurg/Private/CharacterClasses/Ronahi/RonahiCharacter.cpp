// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterClasses/Ronahi/RonahiCharacter.h"

#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

ARonahiCharacter::ARonahiCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	//Camera Boom
	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	CameraSpringArm->SetupAttachment(GetRootComponent());
	//Camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(CameraSpringArm);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

}

void ARonahiCharacter::BeginPlay()
{
	Super::BeginPlay();

	//EnhancedInputSystem
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(Default_RonahiIMC, 0);

		}
	}


}

void ARonahiCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Set up action bindings for input
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {

		EnhancedInputComponent->BindAction(RonahiMoveAction, ETriggerEvent::Triggered, this, &ARonahiCharacter::RonahiMove);
		EnhancedInputComponent->BindAction(RonahiLookAction, ETriggerEvent::Triggered, this, &ARonahiCharacter::RonahiLook);
		EnhancedInputComponent->BindAction(RonahiJumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(RonahiJumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

	}

}

void ARonahiCharacter::RonahiMove(const FInputActionValue& Value)
{
	// input is a Vector2D
	const FVector2D MovementValue = Value.Get<FVector2D>();

	// Find out which way is forward
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	// Get forward vector
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	// Get right vector 
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// Add movement 
	AddMovementInput(ForwardDirection, MovementValue.Y);
	AddMovementInput(RightDirection, MovementValue.X);

}

void ARonahiCharacter::RonahiLook(const FInputActionValue& Value)
{
	const FVector2D LookAxisValue = Value.Get<FVector2D>();

	// add yaw and pitch input to controller
	AddControllerPitchInput(LookAxisValue.Y);
	AddControllerYawInput(LookAxisValue.X);

}
