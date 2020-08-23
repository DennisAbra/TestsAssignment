// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FunctionalTest.h"
#include "Target.h"
#include "MyFunctionalTest.generated.h"

/**
 * 
 */

UCLASS()
class PLEASEWORK_API AMyFunctionalTest : public AFunctionalTest
{
	GENERATED_BODY()

		bool RunTest(const FString parameters);
public:
	UPROPERTY(EditAnywhere)
	ATarget* objectToTest;
	
};