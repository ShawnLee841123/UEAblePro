#pragma once


#include "CoreMinimal.h"
#include "ablAbilityTypes.h"
#include "InputAction.h"
#include "Tasks/IAblAbilityTask.h"
#include "AblEnhancedInputBranch.generated.h"

#define LOCTEXT_NAMESPACE "AblAbilityTask"

/*	find and replace "UAblEnhancedInputBranch" with your task name	*/

/* WE CREATE A SCRATCHPAD AT RUNTIME */
UCLASS(Transient)
class UAblEnhancedInputBranchScratchPad : public UAblAbilityTaskScratchPad
{
	GENERATED_BODY()
public:
	UAblEnhancedInputBranchScratchPad();
	virtual ~UAblEnhancedInputBranchScratchPad();

	void OnInputTriggered(const FInputActionValue& Value);

	uint32_t m_eventHandle;
};

UCLASS()
class ABLECORE_API UAblEnhancedInputBranch : public UAblAbilityTask
{
	GENERATED_BODY()
public:
	/* Constructor and Destructor */
	UAblEnhancedInputBranch(const FObjectInitializer& ObjectInitializer);
	virtual ~UAblEnhancedInputBranch();

	/* Start our Task. */
	virtual void OnTaskStart(const TWeakObjectPtr<const UAblAbilityContext>& Context) const override;
	
	/* End our Task. */
	virtual void OnTaskEnd(const TWeakObjectPtr<const UAblAbilityContext>& Context, const EAblAbilityTaskResult Result) const override;
	
	/* Returns true if our Task only lasts a single frame. */
	virtual bool IsSingleFrame() const override; //set directly in header with { return true/false; } or create a function to decide.
	
	/* Returns the realm this Task belongs to. by default theres is an exposed enum */
	virtual EAblAbilityTaskRealm GetTaskRealm() const override {return m_TaskRealm;}// set directly in header with { return EAblAbilityTaskRealm::ATR_ClientAndServer; }

	/* Creates the Scratchpad for our Task. */
	virtual UAblAbilityTaskScratchPad* CreateScratchPad(const TWeakObjectPtr<UAblAbilityContext>& Context) const;

	/* Returns the Profiler Stat ID for our Task. */
	virtual TStatId GetStatId() const override;
	

	/* Setup Dynamic Binding. */
	virtual void BindDynamicDelegates( UAblAbility* Ability ) override;

	
	/* EDITOR FUNCTIONS	*/
#if WITH_EDITOR
	/* Returns the category for our Task. */
	virtual FText GetTaskCategory() const override { return LOCTEXT("TEMPLATE", "TEMPLATE"); }
	
	/* Returns the name of our Task. */
	virtual FText GetTaskName() const override { return LOCTEXT("TEMPLATE", "CPP TEMPLATE"); }
#endif
		
	/*	VARIABLE EXAMPLES	*/
	UPROPERTY(EditAnywhere, Category = "Realm", meta = (DisplayName = "TaskRealm"))
	TEnumAsByte<EAblAbilityTaskRealm> m_TaskRealm;
	
	UPROPERTY(EditAnywhere, Category="default", meta = (DisplayName = "Input Action"))
	UInputAction* m_InputAction;
	
	UPROPERTY(EditAnywhere, Category="default", meta = (DisplayName = "Input Action"))
	UAblAbility* m_Ability;
};

#undef LOCTEXT_NAMESPACE