#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Logging/LogMacros.h"

#include "RoleBase.generated.h"

class USkeletonComponent;

UCLASS()
class ARoleBase : public APawn
{
	GENERATED_BODY()
public:
	ARoleBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());


protected:

	// To add mapping context
	virtual void BeginPlay() override;

	UPROPERTY(Category = "Role", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> MainMesh;


};