// Copyright 2022 (C) Jakub Mieczkowski

#pragma once

#include "CoreMinimal.h"
#include "SaveFact.generated.h"

/**
* Struct used to store data about facts in Fact Manager
**/
USTRUCT(BlueprintType)
struct FSaveFact
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FName FactName;

	UPROPERTY(BlueprintReadWrite)
	int32 Value;

	UPROPERTY(BlueprintReadWrite)
	int32 ValidFor;
};