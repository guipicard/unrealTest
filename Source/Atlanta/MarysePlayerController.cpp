// Fill out your copyright notice in the Description page of Project Settings.


#include "MarysePlayerController.h"

void AMarysePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent)
	{
		InputComponent->BindAxis("MoveForward", this, &AMarysePlayerController::MoveForward);
		InputComponent->BindAxis("MoveRight", this, &AMarysePlayerController::MoveRight);

		InputComponent->BindAction("Crouch", IE_Pressed, this, &AMarysePlayerController::BeginCrouch);
		InputComponent->BindAction("Crouch", IE_Released, this, &AMarysePlayerController::EndCrouch);
	}
}

void AMarysePlayerController::MoveForward(float AxisValue)
{
	APawn* ControlledPawn = GetPawn();
	if (!ControlledPawn) return;

	FVector forward = ControlledPawn->GetActorForwardVector();
	ControlledPawn->AddMovementInput(forward, AxisValue);
}
void AMarysePlayerController::MoveRight(float AxisValue)
{
	APawn* ControlledPawn = GetPawn();
	if (!ControlledPawn) return;

	FVector right = ControlledPawn->GetActorRightVector();
	ControlledPawn->AddMovementInput(right, AxisValue);
}
void AMarysePlayerController::BeginCrouch()
{
	APawn* ControlledPawn = GetPawn();
	if (!ControlledPawn) return;

	ACharacter* MyCharacter = Cast<ACharacter>(ControlledPawn);
	if (!MyCharacter) return;
	MyCharacter->Crouch();
}
void AMarysePlayerController::EndCrouch()
{
	APawn* ControlledPawn = GetPawn();
	if (!ControlledPawn) return;

	ACharacter* MyCharacter = Cast<ACharacter>(ControlledPawn);
	if (!MyCharacter) return;
	MyCharacter->UnCrouch();
}

