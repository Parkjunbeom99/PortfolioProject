// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "Animation/AnimInstance.h"
#include "PFAnimInstance.generated.h"

/**
 * 
 */
UCLASS(Config = Game)
class PORTFOLIOPROJECT_API UPFAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPFAnimInstance();

	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	void InitializeWithAbilitySystem(UAbilitySystemComponent* ASC);

	UFUNCTION(BlueprintCallable,BlueprintPure)
	UCharacterMovementComponent* GetMovementComponent() const;
protected:
	UPROPERTY(EditDefaultsOnly, Category = "GameplayTags")
	FGameplayTagBlueprintPropertyMap GameplayTagPropertyMap;
	
};
