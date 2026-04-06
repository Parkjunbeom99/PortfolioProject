// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputTriggers.h"
#include "PFInputConfig.h"
#include "EnhancedInputComponent.h" 
#include "PFInputComponent.generated.h"



UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PORTFOLIOPROJECT_API UPFInputComponent : public UEnhancedInputComponent
{
    GENERATED_BODY()

public:

    // 각각의 템플릿 바인딩 함수 구현 
    template<class UserClass, typename FuncType>
    void BindNativeAction(const UPFInputConfig* InputConfig,
       const FGameplayTag& InputTag,
       ETriggerEvent TriggerEvent,
       UserClass* Obj,
       FuncType Func);

    template<class UserClass, typename FuncType, typename RelFuncType>
    void BindAbilityActions(const UPFInputConfig* InputConfig,
       const FGameplayTag& InputTag,
       ETriggerEvent TriggerEvent,
       UserClass* Obj,
       FuncType Func,
       RelFuncType FuncRelease,
       TArray<uint32>& BindHandles);

};

template <class UserClass, typename FuncType>
void UPFInputComponent::BindNativeAction(const UPFInputConfig* InputConfig, const FGameplayTag& InputTag,
    ETriggerEvent TriggerEvent, UserClass* Obj, FuncType Func)
{
    check(InputConfig);
    if (const UInputAction* InputAction = InputConfig->FindNativeInputActionForTag(InputTag))
    {
       BindAction(InputAction, TriggerEvent, Obj, Func);
    }
}

template <class UserClass, typename PressedFuncType, typename ReleasedFuncType>
void UPFInputComponent::BindAbilityActions(const UPFInputConfig* InputConfig, const FGameplayTag& InputTag,
    ETriggerEvent TriggerEvent, UserClass* Obj, PressedFuncType PressedFunc, ReleasedFuncType FuncRelease, TArray<uint32>& BindHandles)
{
    check(InputConfig);
    for (const FPInputAction& Action : InputConfig->AbilityInputActions)
    {
       if (Action.InputAction && Action.InputTag.IsValid())
       {
          if (PressedFunc)
          {
             BindHandles.Add(BindAction(Action.InputAction,
                ETriggerEvent::Triggered,
                Obj,
                PressedFunc,
                Action.InputTag)
                .GetHandle());
             
          }
          if (FuncRelease)
          {
             BindHandles.Add(BindAction(Action.InputAction,
                ETriggerEvent::Completed,
                Obj,
                FuncRelease,
                Action.InputTag)
                .GetHandle());
          }
       }
    }
}