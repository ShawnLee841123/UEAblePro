#include "RoleBase.h"

ARoleBase::ARoleBase(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/):
	Super(ObjectInitializer)
{
}

// To add mapping context
void ARoleBase::BeginPlay()
{
	Super::BeginPlay();

}