// Fill out your copyright notice in the Description page of Project Settings.


#include "PFPlayerCharacter.h"

#include "PFGameplayTags.h"
#include "Input/PFInputComponent.h"


// Sets default values
#include "PFCharacterBase.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "MotionWarpingComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


APFPlayerCharacter::APFPlayerCharacter()
{
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;
	
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	MotionWarpingComponent = CreateDefaultSubobject<UMotionWarpingComponent>(TEXT("MotionWarpingComponent"));

	//Movement Setting
	GetCharacterMovement()->GroundFriction = 1.5f;
	GetCharacterMovement()->BrakingDecelerationWalking = 200.f;
	GetCharacterMovement()->bUseSeparateBrakingFriction = true;

	GetCharacterMovement()->RotationRate =FRotator(0.f,0.f,200.f);
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	
}

// Called to bind functionality to input
void APFPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	BindBaseInput();
}

void APFPlayerCharacter::BindBaseInput()
{
	UPFInputComponent* PFIC = CastChecked<UPFInputComponent>(InputComponent);
	check(PFIC);

	//기본 이동
	PFIC->BindNativeAction(
		BaseInputConfig,
		PFGameplayTags::InputTag_Move,
		ETriggerEvent::Triggered,
		this,
		&APFPlayerCharacter::Input_Move);
	// 바라보기
	PFIC->BindNativeAction(BaseInputConfig,
		PFGameplayTags::InputTag_Look_Mouse,
		ETriggerEvent::Triggered,
		this,
		&APFPlayerCharacter::Input_Look_Mouse);

}

void APFPlayerCharacter::Input_Move(const FInputActionValue& Value)
{
	const FVector2D MoveDir=  Value.Get<FVector2D>();

	if (GetController() != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

		const FVector ForwardDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(ForwardDir, MoveDir.Y);
		AddMovementInput(RightDir, MoveDir.X);
	}
	
}

void APFPlayerCharacter::Input_Look_Mouse(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();
	if (GetController() != nullptr)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}




