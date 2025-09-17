// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySystem/InventoryManagement/Inv_InventoryManagement.h"

// Sets default values for this component's properties
UInv_InventoryManagement::UInv_InventoryManagement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInv_InventoryManagement::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInv_InventoryManagement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

