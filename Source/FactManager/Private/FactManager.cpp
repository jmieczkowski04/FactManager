// Copyright 2022 (C) Jakub Mieczkowski

#include "FactManager.h"

void UFactManager::Init(UWorld* WorldP)
{
	this->World = WorldP;
	StartTimer();
}

void UFactManager::StartTimer()
{
	World->GetTimerManager().SetTimer(TimerHandle, this, &UFactManager::UpdateTimer, 1.0f, true);
}

void UFactManager::StopTimer()
{
	World->GetTimerManager().ClearTimer(TimerHandle);
}

void UFactManager::AddFact(FName Name, int32 Value, int32 ValidFor)
{
	//we're assuming someone write zero seconds by mistake, otherwise it doesn't make sense to call this function
	if (ValidFor == 0)
		ValidFor = -1;
	FFact Fact = {};
	Fact.Value = Value;
	Fact.ValidFor = ValidFor;
	if (Facts.Contains(Name))
	{
		Fact.Value += Facts[Name].Value;
	}
	Facts.Add(Name, Fact);
}

int32 UFactManager::GetFactValue(FName Name)
{
	bool bExist = Facts.Contains(Name);
	if (bExist)
		return Facts[Name].Value;
	return 0;
}

bool UFactManager::DoesFactExist(FName Name)
{
	return Facts.Contains(Name);
}


void UFactManager::RemoveFact(FName Name)
{
	Facts.Remove(Name);
}

void UFactManager::SetFact(FName Name, int32 Value, int32 ValidFor)
{
	//we're assuming someone write zero seconds by mistake, otherwise it doesn't make sense to call this function
	if (ValidFor == 0)
		ValidFor = -1;
	FFact Fact = {};
	Fact.Value = Value;
	Fact.ValidFor = ValidFor;
	Facts.Add(Name, Fact);
}

void UFactManager::UpdateTimer()
{
	TArray<FName> FactsToRemove;
	for (auto& Fact : Facts)
	{
		Fact.Value.ValidFor--;
		if (!Fact.Value.ValidFor)
			FactsToRemove.Add(Fact.Key);
	}

	for (auto& FactName : FactsToRemove)
	{
		Facts.Remove(FactName);
	}
}