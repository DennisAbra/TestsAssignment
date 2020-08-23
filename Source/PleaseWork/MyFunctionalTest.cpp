// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFunctionalTest.h"

bool AMyFunctionalTest::RunTest(const FString parameters)
{
	objectToTest->ApplyDamage_Implementation(50);
	
	return objectToTest->currentHealth < 0;
}



