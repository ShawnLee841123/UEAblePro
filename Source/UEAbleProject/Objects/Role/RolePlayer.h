#pragma once

#include "RoleObject.h"

#include "RolePlayer.generated.h"

UCLASS()
class ARolePlayer : public ARoleObject
{
	GENERATED_BODY()

public:

	ARolePlayer(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:

	// To add mapping context
	virtual void BeginPlay() override;
};
