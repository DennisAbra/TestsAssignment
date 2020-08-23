// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryTest.h"
#include "Tests/AutomationCommon.h"
#include "Tests/AutomationEditorCommon.h"


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAddItemTest, "InventoryTests.Add Item", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FAddItemTest::RunTest(const FString & Parameters)
{
	AMyProjectCharacter* MyChar;
	MyChar = NewObject< AMyProjectCharacter>();

	AWeapon* MyWeapon;
	MyWeapon = NewObject<AWeapon>();
	MyChar->AddWeapon(MyWeapon);

	return MyChar->armoryAmount == 1;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestOverflow, "InventoryTests.Overflow inventory", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FTestOverflow::RunTest(const FString& Parameters)
{
	AMyProjectCharacter* MyChar;
	MyChar = NewObject< AMyProjectCharacter>();

	AWeapon* MyWeapon1;
	AWeapon* MyWeapon2;
	AWeapon* MyWeapon3;
	AWeapon* MyWeapon4;
	AWeapon* MyWeapon5;
	MyWeapon1 = NewObject<AWeapon>();
	MyWeapon2 = NewObject<AWeapon>();
	MyWeapon3 = NewObject<AWeapon>();
	MyWeapon4 = NewObject<AWeapon>();
	MyWeapon5 = NewObject<AWeapon>();
	MyChar->AddWeapon(MyWeapon1);
	MyChar->AddWeapon(MyWeapon2);
	MyChar->AddWeapon(MyWeapon3);
	MyChar->AddWeapon(MyWeapon4);
	MyChar->AddWeapon(MyWeapon5);

	TestTrue("Armory contains first weapon picked up", MyChar->GetArmory().Contains(MyWeapon1));
	TestTrue("Armory contains second weapon picked up", MyChar->GetArmory().Contains(MyWeapon2));
	TestTrue("Armory contains third weapon picked up", MyChar->GetArmory().Contains(MyWeapon3));
	TestTrue("Armory does NOT contain fourth weapon picked up", !MyChar->GetArmory().Contains(MyWeapon4));
	TestTrue("Armory does NOT contain fifth weapon picked up", !MyChar->GetArmory().Contains(MyWeapon5));
	return true;

}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FInvetoryFullTest, "InventoryTests.Inventory full", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FInvetoryFullTest::RunTest(const FString & Parameters)
{
	AMyProjectCharacter* MyChar;
	MyChar = NewObject< AMyProjectCharacter>();

	AWeapon* MyWeapon;
	MyWeapon = NewObject<AWeapon>();
	MyChar->AddWeapon(MyWeapon);
	MyChar->AddWeapon(MyWeapon);
	MyChar->AddWeapon(MyWeapon);
	MyChar->AddWeapon(MyWeapon);

	return MyChar->ArmoryFull();
}

//Switch weapons multiple times. Make sure it goes from first to last back to first
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestSwitchingAllWeapons, "InventoryTests.Switch through all weapons", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FTestSwitchingAllWeapons::RunTest(const FString& Parameters)
{
	AMyProjectCharacter* MyChar;
	MyChar = NewObject< AMyProjectCharacter>();
	AWeapon* MyWeapon1;
	AWeapon* MyWeapon2;
	AWeapon* MyWeapon3;
	MyWeapon1 = NewObject<AWeapon>();
	MyWeapon2 = NewObject<AWeapon>();
	MyWeapon3 = NewObject<AWeapon>();
	MyChar->AddWeapon(MyWeapon1);
	MyChar->AddWeapon(MyWeapon2);
	MyChar->AddWeapon(MyWeapon3);

	MyChar->ChangeWeapon(1);
	TestTrue("Current weapon = weapon2", MyChar->CurrentWeapon() == MyWeapon2);
	MyChar->ChangeWeapon(1);
	TestTrue("Current weapon = weapon3", MyChar->CurrentWeapon() == MyWeapon3);
	MyChar->ChangeWeapon(1);
	TestTrue("Current weapon = weapon1", MyChar->CurrentWeapon() == MyWeapon1);
	MyChar->ChangeWeapon(-1);
	TestTrue("Current weapon = weapon3", MyChar->CurrentWeapon() == MyWeapon3);
	MyChar->ChangeWeapon(-1);
	TestTrue("Current weapon = weapon3", MyChar->CurrentWeapon() == MyWeapon2);
	MyChar->ChangeWeapon(-1);
	TestTrue("Current weapon = weapon3", MyChar->CurrentWeapon() == MyWeapon1);
	return true;
}


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FInventorySwitchTest, "InventoryTests.Change Item", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FInventorySwitchTest::RunTest(const FString & Parameters)
{
	AMyProjectCharacter* MyChar;
	MyChar = NewObject< AMyProjectCharacter>();

	AWeapon* MyWeapon;
	MyWeapon = NewObject<AWeapon>();
	MyChar->AddWeapon(MyWeapon);
	AWeapon* MyWeapon2;
	MyWeapon2 = NewObject<AWeapon>();
	MyChar->AddWeapon(MyWeapon2);

	MyChar->ChangeWeapon(1);


	return MyChar->CurrentWeapon() != MyWeapon;
}


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FInventorySwitchTest2, "InventoryTests.Scroll Item", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FInventorySwitchTest2::RunTest(const FString & Parameters)
{
	AMyProjectCharacter* MyChar;
	MyChar = NewObject< AMyProjectCharacter>();

	AWeapon* MyWeapon;
	MyWeapon = NewObject<AWeapon>();
	MyChar->AddWeapon(MyWeapon);
	AWeapon* MyWeapon2;
	MyWeapon2 = NewObject<AWeapon>();
	MyChar->AddWeapon(MyWeapon2);

	MyChar->ScrollArmory(1);


	return MyChar->CurrentWeapon() != MyWeapon;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDropWeaponTest, "InventoryTests.Drop Item", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FDropWeaponTest::RunTest(const FString & Parameters)
{
	AMyProjectCharacter* MyChar;
	MyChar = NewObject<AMyProjectCharacter>();

	AWeapon* MyWeapon;
	MyWeapon = NewObject<AWeapon>();
	MyChar->AddWeapon(MyWeapon);
	MyChar->DropCurrentWeapon();

	return MyChar->armoryAmount == 0;

}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDropNoWeaponTest, "InventoryTests.Drop without item", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FDropNoWeaponTest::RunTest(const FString & Parameters)
{
	AMyProjectCharacter* MyChar;
	MyChar = NewObject<AMyProjectCharacter>();

	MyChar->DropCurrentWeapon();

	return MyChar->armoryAmount == 0;
}
