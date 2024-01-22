#include "InventoryData.h"

UInventoryData::UInventoryData(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
	:Super(ObjectInitializer)
{
}

#pragma region Special Check
bool UInventoryData::CheckMerchantable()
{
	int32 price = GetMarketPrice();
	return (price > 0);
}

bool UInventoryData::CheckFoldable()
{
	int32 value = GetFoldMax();
	return (value > 1);
}

bool UInventoryData::CheckMeshable()
{
	EInventoryTypes eType = GetInventoryType();
	return (eType >= EInventoryTypes::EIT_PICKABLE);
}
#pragma endregion

#pragma region Attribute Get & Set
void UInventoryData::SetDataID(int32 ID)
{
	DataID = ID;
}

void UInventoryData::SetInventoryType(EInventoryTypes typeValue)
{
	InventoryType = typeValue;
}

void UInventoryData::SetFoldMax(int32 maxValue)
{
	FoldMax = maxValue < 1 ? 1 : maxValue;
	FoldMax = FoldMax > 999 ? 999 : FoldMax;
}

void UInventoryData::SetMarketPrice(int32 price)
{
	MarketPrice = price;
}

void UInventoryData::SetCurrentFoldNum(int32 num)
{
	CurrentFoldNum = num < 0 ? 0 : num;
	CurrentFoldNum = CurrentFoldNum > FoldMax ? FoldMax : CurrentFoldNum;
}

void UInventoryData::SetGlobalID(int64 uID)
{
	GlobalID = uID;
}

int32 UInventoryData::GetDataID()
{
	return DataID;
}

int32 UInventoryData::GetFoldMax()
{
	return FoldMax;
}

int32 UInventoryData::GetMarketPrice()
{
	return MarketPrice;
}

int32 UInventoryData::GetCurrentFoldNum()
{
	return CurrentFoldNum;
}

int64 UInventoryData::GetGlobalID()
{
	return GlobalID;
}

EInventoryTypes UInventoryData::GetInventoryType()
{
	return InventoryType;
}
#pragma endregion