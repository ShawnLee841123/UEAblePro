#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "InventoryData.generated.h"


UENUM()
enum class EEquiptmentSlotType : uint8
{
	EEST_INVALID = 0,
	
	EEST_HAIR,
	EEST_HEAD,
	EEST_MAIN,
	EEST_WAIST,
	EEST_TROUSERS,
	EEST_SHOOTS,
	EEST_LEFTBOWL,
	EEST_RIGHTBOWL,
	EEST_BOWLS,
	EEST_LEFTHAND,
	EEST_RIGHTHAND,
	EEST_HANDS,
	EEST_CLOAK,

};

UENUM()
enum class EInventoryTypes : uint8
{
	EIT_INVALID = 0,
	EIT_CONSUMABLE,
	EIT_MISC,
	
	EIT_INLAY,
	EIT_PICKABLE,
	EIT_EQUIPMENT,
	EIT_WEAPON
};

UCLASS(Blueprintable)
class UInventoryData : public UObject
{
	GENERATED_BODY()
public:

	UInventoryData(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

#pragma region Special Check
	bool CheckMerchantable();
	bool CheckFoldable();
	bool CheckMeshable();
#pragma endregion

#pragma region Attribute Get & Set
	void SetDataID(int32 ID);
	void SetInventoryType(EInventoryTypes typeValue);
	void SetFoldMax(int32 maxValue);
	void SetMarketPrice(int32 price);
	void SetCurrentFoldNum(int32 num);
	void SetGlobalID(int64 uID);

	int32 GetDataID();
	int32 GetFoldMax();
	int32 GetMarketPrice();
	int32 GetCurrentFoldNum();
	int64 GetGlobalID();
	EInventoryTypes GetInventoryType();
#pragma endregion

protected:

#pragma region Attribute
	UPROPERTY(EditAnywhere)
	int32 DataID;

	UPROPERTY(EditAnywhere)
	EInventoryTypes InventoryType;

	UPROPERTY(EditAnywhere, meta = (ClampMin = "1", ClampMax = "999"))
	int32 FoldMax;

	UPROPERTY(EditAnywhere, meta = (ClampMin = "0", ClampMax = "999999999"))
	int32 MarketPrice;

	UPROPERTY(BlueprintReadWrite)
	int32 CurrentFoldNum;

	UPROPERTY(BlueprintReadWrite)
	int64 GlobalID;

#pragma endregion

};