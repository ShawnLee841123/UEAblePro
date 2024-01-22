#pragma once

#include "RoleBase.h"

#include "RoleObject.generated.h"

UCLASS()
class ARoleObject : public ARoleBase
{
	GENERATED_BODY()

public:
	
	ARoleObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:

	// To add mapping context
	virtual void BeginPlay() override;
};