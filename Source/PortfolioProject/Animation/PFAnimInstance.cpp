// Fill out your copyright notice in the Description page of Project Settings.


#include "PFAnimInstance.h"

#include "AbilitySystemGlobals.h"
#include "Character/PFPlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UPFAnimInstance::UPFAnimInstance()
{
}

void UPFAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (AActor* OwningActor = GetOwningActor())
	{
		if (UAbilitySystemComponent* ASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(OwningActor))
		{
			InitializeWithAbilitySystem(ASC);
		}
	}
}

void UPFAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	

}

void UPFAnimInstance::InitializeWithAbilitySystem(UAbilitySystemComponent* ASC)
{
	check(ASC);

	GameplayTagPropertyMap.Initialize(this, ASC);
}

UCharacterMovementComponent* UPFAnimInstance::GetMovementComponent() const
{
	const APFPlayerCharacter* Character = Cast<APFPlayerCharacter>(GetOwningActor());
	if (!Character)
	{
		return nullptr;
	}

	UCharacterMovementComponent* CharMoveComp = CastChecked<UCharacterMovementComponent>(Character->GetCharacterMovement());

	check(CharMoveComp);

	return CharMoveComp;
	
}

