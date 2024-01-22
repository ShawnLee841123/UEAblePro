#include "Tasks/AblEnhancedInputBranch.h"
#include "ablAbility.h"
#include "AbleCorePrivate.h"
#include "ablAbilityComponent.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"

/* Create our scratchpad */
UAblEnhancedInputBranchScratchPad::UAblEnhancedInputBranchScratchPad()
: m_eventHandle(0xFFFFFFFF)
{
}
UAblEnhancedInputBranchScratchPad::~UAblEnhancedInputBranchScratchPad()
{
}

void UAblEnhancedInputBranchScratchPad::OnInputTriggered(const FInputActionValue& Value)
{
   // Do whatever?
}

/* Construct and deconstruct task and set default parameters */
UAblEnhancedInputBranch::UAblEnhancedInputBranch(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer),
m_TaskRealm(ATR_ClientAndServer)
{
}
UAblEnhancedInputBranch::~UAblEnhancedInputBranch()
{
}

/* MAIN FUNCTIONS */
void UAblEnhancedInputBranch::OnTaskStart(const TWeakObjectPtr<const UAblAbilityContext>& Context) const
{
	Super::OnTaskStart(Context);

	if (!m_InputAction)
	{
		// No action, just bounce out.
		return;
	}

	if (const APawn* Pawn = Cast<APawn>(Context->GetSelfActor()))
	{
		if (const APlayerController* PlayerController = Cast<APlayerController>(Pawn->GetController()))
		{
			if (UEnhancedInputComponent* PlayerEnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent))
			{
				UAblEnhancedInputBranchScratchPad* scratchPad = Cast<UAblEnhancedInputBranchScratchPad>(Context->GetScratchPadForTask(this));

				FEnhancedInputActionEventBinding& boundAction = PlayerEnhancedInputComponent->BindAction(
				m_InputAction, 
				ETriggerEvent::Triggered, 
				scratchPad, 
				&UAblEnhancedInputBranchScratchPad::OnInputTriggered);

				scratchPad->m_eventHandle = boundAction.GetHandle();
			}
		}
	}
}

void UAblEnhancedInputBranch::OnTaskEnd(const TWeakObjectPtr<const UAblAbilityContext>& Context, const EAblAbilityTaskResult Result) const
{
	Super::OnTaskEnd(Context, Result);

	if (!m_InputAction)
	{
		return;
	}

	if (const APawn* Pawn = Cast<APawn>(Context->GetSelfActor()))
	{
		if (const APlayerController* PlayerController = Cast<APlayerController>(Pawn->GetController()))
		{
			if (UEnhancedInputComponent* PlayerEnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent))
			{
				UAblEnhancedInputBranchScratchPad* scratchPad = Cast<UAblEnhancedInputBranchScratchPad>(Context->GetScratchPadForTask(this));
				if (scratchPad->m_eventHandle != 0xFFFFFFFF)
				{
					PlayerEnhancedInputComponent->RemoveActionEventBinding(scratchPad->m_eventHandle);
				}
			}
		}
	}

}

bool UAblEnhancedInputBranch::IsSingleFrame() const
{
	return Super::IsSingleFrame();
}

/* Create our Scratchpad */
UAblAbilityTaskScratchPad* UAblEnhancedInputBranch::CreateScratchPad(const TWeakObjectPtr<UAblAbilityContext>& Context) const
{
	return NewObject<UAblEnhancedInputBranchScratchPad>(Context.Get());
}

/* declare an ID, needs a unique ID, usually the name of your task,with the default STATGROUP_Able */
TStatId UAblEnhancedInputBranch::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UAblEnhancedInputBranch, STATGROUP_Able);
}

/* function that allows us to set parameters and dynamic.  */
void UAblEnhancedInputBranch::BindDynamicDelegates(UAblAbility* Ability)
{
	Super::BindDynamicDelegates(Ability);
	/* Example property binding TEXT, must match the Displayname of the UProperty */
	/* ABL_BIND_DYNAMIC_PROPERTY(Ability, m_Vector, TEXT("Vector"));	*/
}

