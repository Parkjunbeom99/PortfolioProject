// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PFCharacterBase.h"
#include "PFPlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UPFInputConfig;
class UMotionWarpingComponent;
struct FInputActionValue;

UCLASS()
class PORTFOLIOPROJECT_API APFPlayerCharacter : public APFCharacterBase
{
	GENERATED_BODY()


public:
	APFPlayerCharacter();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<UCameraComponent> FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MotionWarping")
	TObjectPtr<UMotionWarpingComponent> MotionWarpingComponent;
	
#pragma region Input

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPFInputConfig> BaseInputConfig;

	// 기본 인풋 바인딩 
	void BindBaseInput();
	void Input_Move(const FInputActionValue& Value);
	void Input_Look_Mouse(const FInputActionValue& Value);

#pragma endregion
};
