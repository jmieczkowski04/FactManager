// Copyright 2022 (C) Jakub Mieczkowski

#pragma once

#include "CoreMinimal.h"
#include "Fact.generated.h"

/**
* Struct used to store data about facts in Fact Manager
**/
USTRUCT()
struct FFact
{
	GENERATED_BODY()

	int32 Value;
	int32 ValidFor;
};