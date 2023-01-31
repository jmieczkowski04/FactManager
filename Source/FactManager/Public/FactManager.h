// Copyright 2022 (C) Jakub Mieczkowski

#pragma once

#include "CoreMinimal.h"
#include "Fact.h"
#include "FactManager.generated.h"


/**
* Fact Manager. Keeps values for specified amount of time under FName tag
*/
UCLASS(BlueprintType)
class FACTMANAGER_API UFactManager : public UObject
{
	GENERATED_BODY()
public:

	/**
	* Initialization code. Start timer
	* 
	* @param sWorldP Pointer to world. Use GetWorld()
	*/
	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void Init(UWorld* WorldP);

	/**
	* Starts timer if paused
	*/
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void StartTimer();

	/**
	* Stops timer if running
	*/
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void StopTimer();

	/**
	* Adds fact. If fact alredy exist adds value and make it valid for given number of seconds. Similar to SetFact,
	* but with different behaviour when fact exists
	* @param Name		Fact name
	* @param Value		Fact value. Default 1
	* @param ValidFor	Time in seconds describing how long fact is valid. Values < 1 means valid forever. Default -1
	*/
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void AddFact(FName Name, int32 Value = 1, int32 ValidFor = -1);

	/**
	* Finds fact value. If fact doesn't exist return 0.
	* @param Name Fact name
	* @return Fact value
	*/
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	int32 GetFactValue(FName Name);

	/**
	* Checks if fact exists
	* @param Name Fact name
	* @return true if exists
	*/
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	bool DoesFactExist(FName Name);

	/**
	* Removes facts
	* @param Name Fact names
	*/
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void RemoveFact(FName Name);

	/**
	* Sets fact. If fact alredy exist overrides it. Similar to SetFact, but with different behaviour when fact exists
	* @param Name		Fact name
	* @param Value		Fact value. Default 1
	* @param ValidFor	Time in seconds describing how long fact is valid. Values < 1 means valid forever. Default -1
	*/
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void SetFact(FName Name, int32 Value = 1, int32 ValidFor = -1);

protected:
	void UpdateTimer();

protected:
	UPROPERTY()
	TMap<FName, FFact> Facts;
	UPROPERTY()
	FTimerHandle TimerHandle;
	UPROPERTY()
	UWorld* World;
};

