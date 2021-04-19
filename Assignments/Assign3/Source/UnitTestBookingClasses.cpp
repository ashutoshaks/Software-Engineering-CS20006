/*
    CS20006 Assignment 3
    UnitTestBookingClasses.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

/*
    COMPILATION AND BUILD COMMANDS :
    g++ -std=c++11 BookingClasses.cpp UnitTestBookingClasses.cpp -o test
    ./test
*/

// Unit Testing File for the hierarchy of booking classes

// Including project header files
#include "BookingClasses.h"

// C++ Headers
#include <cassert>
#include <sstream>

// Initializing the required static constants
const double ACFirstClass::sLoadFactor = 3.00;
const double AC2Tier::sLoadFactor = 2.00;
const double FirstClass::sLoadFactor = 2.00;
const double AC3Tier::sLoadFactor = 1.75;
const double ACChairCar::sLoadFactor = 1.25;
const double Sleeper::sLoadFactor = 1.00;
const double SecondSitting::sLoadFactor = 0.50;

void ACFirstClass::UnitTestACFirstClass()
{
    // Testing the Type() function (constructor automatically gets tested during this)
    // To test the singleton behaviour, we compare the addresses of the objects after calling Type() for the first and second time
    const ACFirstClass* firstPointer = &ACFirstClass::Type(); // First Call
    const ACFirstClass* secondPointer = &ACFirstClass::Type(); // Second Call
    assert(firstPointer == secondPointer); // Compare both the addresses for equality

    assert(3.0 == ACFirstClass::Type().GetLoadFactor()); // Testing GetLoadFactor()
    assert("AC First Class" == ACFirstClass::Type().GetName()); // Testing GetName()
    assert(false == ACFirstClass::Type().IsSitting()); // Testing IsSitting()
    assert(true == ACFirstClass::Type().IsAC()); // Testing IsAC()
    assert(2 == ACFirstClass::Type().GetNumberOfTiers()); // Testing GetNumberOfTiers()
    assert(true == ACFirstClass::Type().IsLuxury()); // Testing IsLuxury()

    // Testing the ostream operator
    stringstream out;
    out << ACFirstClass::Type();

    string expectedOutput = "Travel Class = AC First Class\n  : Mode: Sleeping\n  : Comfort: AC\n  : Bunks: 2\n  : Luxury: Yes\n";
    assert(expectedOutput == out.str()); // Match the output with the expected output

    // Also print the object to the screen for better clarity
    cout << ACFirstClass::Type();

    // If the control has reached here, it means that all unit tests have passed
    cout << "\n*** ALL UNIT TESTS FOR CLASS ACFirstClass PASSED ***\n\n";

}

void AC2Tier::UnitTestAC2Tier()
{
    // Testing the Type() function (constructor automatically gets tested during this)
    // To test the singleton behaviour, we compare the addresses of the objects after calling Type() for the first and second time
    const AC2Tier* firstPointer = &AC2Tier::Type(); // First call
    const AC2Tier* secondPointer = &AC2Tier::Type(); // Second call
    assert(firstPointer == secondPointer); // Compare both the addresses for equality

    assert(2.0 == AC2Tier::Type().GetLoadFactor()); // Testing GetLoadFactor()
    assert("AC 2 Tier" == AC2Tier::Type().GetName()); // Testing GetName()
    assert(false == AC2Tier::Type().IsSitting()); // Testing IsSitting()
    assert(true == AC2Tier::Type().IsAC()); // Testing IsAC()
    assert(2 == AC2Tier::Type().GetNumberOfTiers()); // Testing GetNumberOfTiers()
    assert(false == AC2Tier::Type().IsLuxury()); // Testing IsLuxury()

    // Testing the ostream operator
    stringstream out;
    out << AC2Tier::Type();

    string expectedOutput = "Travel Class = AC 2 Tier\n  : Mode: Sleeping\n  : Comfort: AC\n  : Bunks: 2\n  : Luxury: No\n";
    assert(expectedOutput == out.str()); // Match the output with the expected output

    // Also print the object to the screen for better clarity
    cout << AC2Tier::Type();

    // If the control has reached here, it means that all unit tests have passed
    cout << "\n*** ALL UNIT TESTS FOR CLASS AC2Tier PASSED ***\n\n";
}

void FirstClass::UnitTestFirstClass()
{
    // Testing the Type() function (constructor automatically gets tested during this)
    // To test the singleton behaviour, we compare the addresses of the objects after calling Type() for the first and second time
    const FirstClass* firstPointer = &FirstClass::Type(); // First call
    const FirstClass* secondPointer = &FirstClass::Type(); // Second call
    assert(firstPointer == secondPointer); // Compare both the addresses for equality

    assert(2.0 == FirstClass::Type().GetLoadFactor()); // Testing GetLoadFactor()
    assert("First Class" == FirstClass::Type().GetName()); // Testing GetName()
    assert(false == FirstClass::Type().IsSitting()); // Testing IsSitting()
    assert(false == FirstClass::Type().IsAC()); // Testing IsAC()
    assert(2 == FirstClass::Type().GetNumberOfTiers()); // Testing GetNumberOfTiers()
    assert(true == FirstClass::Type().IsLuxury()); // Testing IsLuxury()

    // Testing the ostream operator
    stringstream out;
    out << FirstClass::Type();

    string expectedOutput = "Travel Class = First Class\n  : Mode: Sleeping\n  : Comfort: Non-AC\n  : Bunks: 2\n  : Luxury: Yes\n";
    assert(expectedOutput == out.str()); // Match the output with the expected output

    // Also print the object to the screen for better clarity
    cout << FirstClass::Type();

    // If the control has reached here, it means that all unit tests have passed
    cout << "\n*** ALL UNIT TESTS FOR CLASS FirstClass PASSED ***\n\n";
}

void AC3Tier::UnitTestAC3Tier()
{
    // Testing the Type() function (constructor automatically gets tested during this)
    // To test the singleton behaviour, we compare the addresses of the objects after calling Type() for the first and second time
    const AC3Tier* firstPointer = &AC3Tier::Type(); // First call
    const AC3Tier* secondPointer = &AC3Tier::Type(); // Second call
    assert(firstPointer == secondPointer); // Compare both the addresses for equality

    assert(1.75 == AC3Tier::Type().GetLoadFactor()); // Testing GetLoadFactor()
    assert("AC 3 Tier" == AC3Tier::Type().GetName()); // Testing GetName()
    assert(false == AC3Tier::Type().IsSitting()); // Testing IsSitting()
    assert(true == AC3Tier::Type().IsAC()); // Testing IsAC()
    assert(3 == AC3Tier::Type().GetNumberOfTiers()); // Testing GetNumberOfTiers()
    assert(false == AC3Tier::Type().IsLuxury()); // Testing IsLuxury()

    // Testing the ostream operator
    stringstream out;
    out << AC3Tier::Type();

    string expectedOutput = "Travel Class = AC 3 Tier\n  : Mode: Sleeping\n  : Comfort: AC\n  : Bunks: 3\n  : Luxury: No\n";
    assert(expectedOutput == out.str()); // Match the output with the expected output

    // Also print the object to the screen for better clarity
    cout << AC3Tier::Type();

    // If the control has reached here, it means that all unit tests have passed
    cout << "\n*** ALL UNIT TESTS FOR CLASS AC3Tier PASSED ***\n\n";
}

void ACChairCar::UnitTestACChairCar()
{
    // Testing the Type() function (constructor automatically gets tested during this)
    // To test the singleton behaviour, we compare the addresses of the objects after calling Type() for the first and second time
    const ACChairCar* firstPointer = &ACChairCar::Type(); // First call
    const ACChairCar* secondPointer = &ACChairCar::Type(); // Second call
    assert(firstPointer == secondPointer); // Compare both the addresses for equality

    assert(1.25 == ACChairCar::Type().GetLoadFactor()); // Testing GetLoadFactor()
    assert("AC Chair Car" == ACChairCar::Type().GetName()); // Testing GetName()
    assert(true == ACChairCar::Type().IsSitting()); // Testing IsSitting()
    assert(true == ACChairCar::Type().IsAC()); // Testing IsAC()
    assert(0 == ACChairCar::Type().GetNumberOfTiers()); // Testing GetNumberOfTiers()
    assert(false == ACChairCar::Type().IsLuxury()); // Testing IsLuxury()

    // Testing the ostream operator
    stringstream out;
    out << ACChairCar::Type();

    string expectedOutput = "Travel Class = AC Chair Car\n  : Mode: Sitting\n  : Comfort: AC\n  : Bunks: 0\n  : Luxury: No\n";
    assert(expectedOutput == out.str()); // Match the output with the expected output

    // Also print the object to the screen for better clarity
    cout << ACChairCar::Type();

    // If the control has reached here, it means that all unit tests have passed
    cout << "\n*** ALL UNIT TESTS FOR CLASS ACChairCar PASSED ***\n\n";
}

void Sleeper::UnitTestSleeper()
{
    // Testing the Type() function (constructor automatically gets tested during this)
    // To test the singleton behaviour, we compare the addresses of the objects after calling Type() for the first and second time
    const Sleeper* firstPointer = &Sleeper::Type(); // First call
    const Sleeper* secondPointer = &Sleeper::Type(); // Second call
    assert(firstPointer == secondPointer); // Compare both the addresses for equality

    assert(1.0 == Sleeper::Type().GetLoadFactor()); // Testing GetLoadFactor()
    assert("Sleeper" == Sleeper::Type().GetName()); // Testing GetName()
    assert(false == Sleeper::Type().IsSitting()); // Testing IsSitting()
    assert(false == Sleeper::Type().IsAC()); // Testing IsAC()
    assert(3 == Sleeper::Type().GetNumberOfTiers()); // Testing GetNumberOfTiers()
    assert(false == Sleeper::Type().IsLuxury()); // Testing IsLuxury()

    // Testing the ostream operator
    stringstream out;
    out << Sleeper::Type();

    string expectedOutput = "Travel Class = Sleeper\n  : Mode: Sleeping\n  : Comfort: Non-AC\n  : Bunks: 3\n  : Luxury: No\n";
    assert(expectedOutput == out.str()); // Match the output with the expected output

    // Also print the object to the screen for better clarity
    cout << Sleeper::Type();

    // If the control has reached here, it means that all unit tests have passed
    cout << "\n*** ALL UNIT TESTS FOR CLASS Sleeper PASSED ***\n\n";
}

void SecondSitting::UnitTestSecondSitting()
{
    // Testing the Type() function (constructor automatically gets tested during this)
    // To test the singleton behaviour, we compare the addresses of the objects after calling Type() for the first and second time
    const SecondSitting* firstPointer = &SecondSitting::Type(); // First call
    const SecondSitting* secondPointer = &SecondSitting::Type(); // Second call
    assert(firstPointer == secondPointer); // Compare both the addresses for equality

    assert(0.5 == SecondSitting::Type().GetLoadFactor()); // Testing GetLoadFactor()
    assert("Second Sitting" == SecondSitting::Type().GetName()); // Testing GetName()
    assert(true == SecondSitting::Type().IsSitting()); // Testing IsSitting()
    assert(false == SecondSitting::Type().IsAC()); // Testing IsAC()
    assert(0 == SecondSitting::Type().GetNumberOfTiers()); // Testing GetNumberOfTiers()
    assert(false == SecondSitting::Type().IsLuxury()); // Testing IsLuxury()

    // Testing the ostream operator
    stringstream out;
    out << SecondSitting::Type();

    string expectedOutput = "Travel Class = Second Sitting\n  : Mode: Sitting\n  : Comfort: Non-AC\n  : Bunks: 0\n  : Luxury: No\n";
    assert(expectedOutput == out.str()); // Match the output with the expected output

    // Also print the object to the screen for better clarity
    cout << SecondSitting::Type();

    // If the control has reached here, it means that all unit tests have passed
    cout << "\n*** ALL UNIT TESTS FOR CLASS SecondSitting PASSED ***\n\n";
}

int main()
{
    ACFirstClass::UnitTestACFirstClass();
    AC2Tier::UnitTestAC2Tier();
    FirstClass::UnitTestFirstClass();
    AC3Tier::UnitTestAC3Tier();
    ACChairCar::UnitTestACChairCar();
    Sleeper::UnitTestSleeper();
    SecondSitting::UnitTestSecondSitting();

    return 0;
}