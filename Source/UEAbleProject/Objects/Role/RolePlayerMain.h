#pragma once

#include "RolePlayer.h"

#include "RolePlayerMain.generated.h"

UCLASS()
class ARolePlayerMain : public ARolePlayer
{
	GENERATED_BODY()
	
public:

	ARolePlayerMain(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:

	// To add mapping context
	virtual void BeginPlay() override;
};