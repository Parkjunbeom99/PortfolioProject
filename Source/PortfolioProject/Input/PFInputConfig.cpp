// Fill out your copyright notice in the Description page of Project Settings.


#include "PFInputConfig.h"

const UInputAction* UPFInputConfig::FindNativeInputActionForTag(const FGameplayTag& InputTag) const
{
	for (const FPInputAction& Action : NativeInputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}

	return nullptr;
}

const UInputAction* UPFInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag) const
{
	for (const FPInputAction& Action : AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}

	return nullptr;
}
