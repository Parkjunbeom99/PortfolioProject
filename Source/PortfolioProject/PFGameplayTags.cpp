// Fill out your copyright notice in the Description page of Project Settings.


#include "PFGameplayTags.h"

namespace PFGameplayTags
{
	// Native Input
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look_Mouse, "InputTag.Look.Mouse");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Crouch, "InputTag.Crouch");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Sprint, "InputTag.Sprint");
    
	// Ability Input
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Ability_Jump, "InputTag.Ability.Jump");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Ability_Dash, "InputTag.Ability.Dash");
}