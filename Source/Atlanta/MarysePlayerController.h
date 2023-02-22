// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"
#include "MarysePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ATLANTA_API AMarysePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void SetupInputComponent() override;
private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void BeginCrouch();
	void EndCrouch();
	
};
