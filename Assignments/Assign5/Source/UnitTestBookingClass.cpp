/*
    CS20006 Assignment 5
    UnitTestBookingClass.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

/*
    COMPILATION AND BUILD COMMANDS :
    g++ -std=c++11 BookingClass.cpp UnitTestBookingClass.cpp -o test
    ./test
*/

// Unit Testing File for the hierarchy of booking classes

// Including project header files
#include "BookingClass.h"

// C++ Headers
#include <cassert>
#include <sstream>

// Initializing the required static constants
template<> const double BookingClass::ACFirstClass::sLoadFactor = 6.50;
template<> const bool BookingClass::ACFirstClass::sIsLuxury = true;
template<> const double BookingClass::ACFirstClass::sReservationCharge = 60.00;
template<> const double BookingClass::ACFirstClass::sTatkalLoadFactor = 0.30;
template<> const double BookingClass::ACFirstClass::sMinTatkalCharge = 400.00;
template<> const double BookingClass::ACFirstClass::sMaxTatkalCharge = 500.00;
template<> const int BookingClass::ACFirstClass::sMinTatkalDistance = 500;

template<> const double BookingClass::ExecutiveChairCar::sLoadFactor = 5.00;
template<> const bool BookingClass::ExecutiveChairCar::sIsLuxury = true;
template<> const double BookingClass::ExecutiveChairCar::sReservationCharge = 60.00;
template<> const double BookingClass::ExecutiveChairCar::sTatkalLoadFactor = 0.30;
template<> const double BookingClass::ExecutiveChairCar::sMinTatkalCharge = 400.00;
template<> const double BookingClass::ExecutiveChairCar::sMaxTatkalCharge = 500.00;
template<> const int BookingClass::ExecutiveChairCar::sMinTatkalDistance = 250;

template<> const double BookingClass::AC2Tier::sLoadFactor = 4.00;
template<> const bool BookingClass::AC2Tier::sIsLuxury = false;
template<> const double BookingClass::AC2Tier::sReservationCharge = 50.00;
template<> const double BookingClass::AC2Tier::sTatkalLoadFactor = 0.30;
template<> const double BookingClass::AC2Tier::sMinTatkalCharge = 400.00;
template<> const double BookingClass::AC2Tier::sMaxTatkalCharge = 500.00;
template<> const int BookingClass::AC2Tier::sMinTatkalDistance = 500;

template<> const double BookingClass::FirstClass::sLoadFactor = 3.00;
template<> const bool BookingClass::FirstClass::sIsLuxury = true;
template<> const double BookingClass::FirstClass::sReservationCharge = 50.00;
template<> const double BookingClass::FirstClass::sTatkalLoadFactor = 0.30;
template<> const double BookingClass::FirstClass::sMinTatkalCharge = 400.00;
template<> const double BookingClass::FirstClass::sMaxTatkalCharge = 500.00;
template<> const int BookingClass::FirstClass::sMinTatkalDistance = 500;

template<> const double BookingClass::AC3Tier::sLoadFactor = 2.50;
template<> const bool BookingClass::AC3Tier::sIsLuxury = false;
template<> const double BookingClass::AC3Tier::sReservationCharge = 40.00;
template<> const double BookingClass::AC3Tier::sTatkalLoadFactor = 0.30;
template<> const double BookingClass::AC3Tier::sMinTatkalCharge = 300.00;
template<> const double BookingClass::AC3Tier::sMaxTatkalCharge = 400.00;
template<> const int BookingClass::AC3Tier::sMinTatkalDistance = 500;

template<> const double BookingClass::ACChairCar::sLoadFactor = 2.00;
template<> const bool BookingClass::ACChairCar::sIsLuxury = false;
template<> const double BookingClass::ACChairCar::sReservationCharge = 40.00;
template<> const double BookingClass::ACChairCar::sTatkalLoadFactor = 0.30;
template<> const double BookingClass::ACChairCar::sMinTatkalCharge = 125.00;
template<> const double BookingClass::ACChairCar::sMaxTatkalCharge = 225.00;
template<> const int BookingClass::ACChairCar::sMinTatkalDistance = 250;

template<> const double BookingClass::Sleeper::sLoadFactor = 1.00;
template<> const bool BookingClass::Sleeper::sIsLuxury = false;
template<> const double BookingClass::Sleeper::sReservationCharge = 20.00;
template<> const double BookingClass::Sleeper::sTatkalLoadFactor = 0.30;
template<> const double BookingClass::Sleeper::sMinTatkalCharge = 100.00;
template<> const double BookingClass::Sleeper::sMaxTatkalCharge = 200.00;
template<> const int BookingClass::Sleeper::sMinTatkalDistance = 500;

template<> const double BookingClass::SecondSitting::sLoadFactor = 0.60;
template<> const bool BookingClass::SecondSitting::sIsLuxury = false;
template<> const double BookingClass::SecondSitting::sReservationCharge = 15.00;
template<> const double BookingClass::SecondSitting::sTatkalLoadFactor = 0.10;
template<> const double BookingClass::SecondSitting::sMinTatkalCharge = 10.00;
template<> const double BookingClass::SecondSitting::sMaxTatkalCharge = 15.00;
template<> const int BookingClass::SecondSitting::sMinTatkalDistance = 100;

template<>
void BookingClass::ACFirstClass::UnitTest() {
    // Testing the Type() function (constructor automatically gets tested during this)
    // To test the singleton behaviour, we compare the addresses of the objects after calling Type() for the first and second time
    const BookingClass::ACFirstClass* firstPointer = &BookingClass::ACFirstClass::Type(); // First Call
    const BookingClass::ACFirstClass* secondPointer = &BookingClass::ACFirstClass::Type(); // Second Call
    assert(firstPointer == secondPointer); // Compare both the addresses for equality

    assert(6.50 == BookingClass::ACFirstClass::Type().GetLoadFactor()); // Testing GetLoadFactor()
    assert("AC First Class" == BookingClass::ACFirstClass::Type().GetName()); // Testing GetName()
    assert(false == BookingClass::ACFirstClass::Type().IsSitting()); // Testing IsSitting()
    assert(true == BookingClass::ACFirstClass::Type().IsAC()); // Testing IsAC()
    assert(2 == BookingClass::ACFirstClass::Type().GetNumberOfTiers()); // Testing GetNumberOfTiers()
    assert(true == BookingClass::ACFirstClass::Type().IsLuxury()); // Testing IsLuxury()
    assert(60.00 == BookingClass::ACFirstClass::Type().GetReservationCharge());
    assert(0.30 == BookingClass::ACFirstClass::Type().GetTatkalLoadFactor());
    assert(400.00 == BookingClass::ACFirstClass::Type().GetMinTatkalCharge());
    assert(500.00 == BookingClass::ACFirstClass::Type().GetMaxTatkalCharge());
    assert(500 == BookingClass::ACFirstClass::Type().GetMinTatkalDistance());


    // Testing the ostream operator
    stringstream out;
    out << BookingClass::ACFirstClass::Type();

    string expectedOutput = "Travel Class = AC First Class\n  : Mode: Sleeping\n  : Comfort: AC\n  : Bunks: 2\n  : Luxury: Yes\n";
    assert(expectedOutput == out.str()); // Match the output with the expected output

    // Also print the object to the screen for better clarity
    cout << BookingClass::ACFirstClass::Type() << endl;
}

template<>
void BookingClass::ExecutiveChairCar::UnitTest() {
    // Testing the Type() function (constructor automatically gets tested during this)
    // To test the singleton behaviour, we compare the addresses of the objects after calling Type() for the first and second time
    const BookingClass::ExecutiveChairCar* firstPointer = &BookingClass::ExecutiveChairCar::Type(); // First Call
    const BookingClass::ExecutiveChairCar* secondPointer = &BookingClass::ExecutiveChairCar::Type(); // Second Call
    assert(firstPointer == secondPointer); // Compare both the addresses for equality

    assert(5.00 == BookingClass::ExecutiveChairCar::Type().GetLoadFactor()); // Testing GetLoadFactor()
    assert("Executive Chair Car" == BookingClass::ExecutiveChairCar::Type().GetName()); // Testing GetName()
    assert(true == BookingClass::ExecutiveChairCar::Type().IsSitting()); // Testing IsSitting()
    assert(true == BookingClass::ExecutiveChairCar::Type().IsAC()); // Testing IsAC()
    assert(0 == BookingClass::ExecutiveChairCar::Type().GetNumberOfTiers()); // Testing GetNumberOfTiers()
    assert(true == BookingClass::ExecutiveChairCar::Type().IsLuxury()); // Testing IsLuxury()
    assert(60.00 == BookingClass::ExecutiveChairCar::Type().GetReservationCharge());
    assert(0.30 == BookingClass::ExecutiveChairCar::Type().GetTatkalLoadFactor());
    assert(400.00 == BookingClass::ExecutiveChairCar::Type().GetMinTatkalCharge());
    assert(500.00 == BookingClass::ExecutiveChairCar::Type().GetMaxTatkalCharge());
    assert(250 == BookingClass::ExecutiveChairCar::Type().GetMinTatkalDistance());


    // Testing the ostream operator
    stringstream out;
    out << BookingClass::ExecutiveChairCar::Type();

    string expectedOutput = "Travel Class = Executive Chair Car\n  : Mode: Sitting\n  : Comfort: AC\n  : Bunks: 0\n  : Luxury: Yes\n";
    assert(expectedOutput == out.str()); // Match the output with the expected output

    // Also print the object to the screen for better clarity
    cout << BookingClass::ExecutiveChairCar::Type() << endl;
}

template<>
void BookingClass::AC2Tier::UnitTest() {
    // Testing the Type() function (constructor automatically gets tested during this)
    // To test the singleton behaviour, we compare the addresses of the objects after calling Type() for the first and second time
    const BookingClass::AC2Tier* firstPointer = &BookingClass::AC2Tier::Type(); // First Call
    const BookingClass::AC2Tier* secondPointer = &BookingClass::AC2Tier::Type(); // Second Call
    assert(firstPointer == secondPointer); // Compare both the addresses for equality

    assert(4.00 == BookingClass::AC2Tier::Type().GetLoadFactor()); // Testing GetLoadFactor()
    assert("AC 2 Tier" == BookingClass::AC2Tier::Type().GetName()); // Testing GetName()
    assert(false == BookingClass::AC2Tier::Type().IsSitting()); // Testing IsSitting()
    assert(true == BookingClass::AC2Tier::Type().IsAC()); // Testing IsAC()
    assert(2 == BookingClass::AC2Tier::Type().GetNumberOfTiers()); // Testing GetNumberOfTiers()
    assert(false == BookingClass::AC2Tier::Type().IsLuxury()); // Testing IsLuxury()
    assert(50.00 == BookingClass::AC2Tier::Type().GetReservationCharge());
    assert(0.30 == BookingClass::AC2Tier::Type().GetTatkalLoadFactor());
    assert(400.00 == BookingClass::AC2Tier::Type().GetMinTatkalCharge());
    assert(500.00 == BookingClass::AC2Tier::Type().GetMaxTatkalCharge());
    assert(500 == BookingClass::AC2Tier::Type().GetMinTatkalDistance());


    // Testing the ostream operator
    stringstream out;
    out << BookingClass::AC2Tier::Type();

    string expectedOutput = "Travel Class = AC 2 Tier\n  : Mode: Sleeping\n  : Comfort: AC\n  : Bunks: 2\n  : Luxury: No\n";
    assert(expectedOutput == out.str()); // Match the output with the expected output

    // Also print the object to the screen for better clarity
    cout << BookingClass::AC2Tier::Type() << endl;
}

template<>
void BookingClass::FirstClass::UnitTest() {
    // Testing the Type() function (constructor automatically gets tested during this)
    // To test the singleton behaviour, we compare the addresses of the objects after calling Type() for the first and second time
    const BookingClass::FirstClass* firstPointer = &BookingClass::FirstClass::Type(); // First Call
    const BookingClass::FirstClass* secondPointer = &BookingClass::FirstClass::Type(); // Second Call
    assert(firstPointer == secondPointer); // Compare both the addresses for equality

    assert(3.00 == BookingClass::FirstClass::Type().GetLoadFactor()); // Testing GetLoadFactor()
    assert("First Class" == BookingClass::FirstClass::Type().GetName()); // Testing GetName()
    assert(false == BookingClass::FirstClass::Type().IsSitting()); // Testing IsSitting()
    assert(false == BookingClass::FirstClass::Type().IsAC()); // Testing IsAC()
    assert(2 == BookingClass::FirstClass::Type().GetNumberOfTiers()); // Testing GetNumberOfTiers()
    assert(true == BookingClass::FirstClass::Type().IsLuxury()); // Testing IsLuxury()
    assert(50.00 == BookingClass::FirstClass::Type().GetReservationCharge());
    assert(0.30 == BookingClass::FirstClass::Type().GetTatkalLoadFactor());
    assert(400.00 == BookingClass::FirstClass::Type().GetMinTatkalCharge());
    assert(500.00 == BookingClass::FirstClass::Type().GetMaxTatkalCharge());
    assert(500 == BookingClass::FirstClass::Type().GetMinTatkalDistance());


    // Testing the ostream operator
    stringstream out;
    out << BookingClass::FirstClass::Type();

    string expectedOutput = "Travel Class = First Class\n  : Mode: Sleeping\n  : Comfort: Non-AC\n  : Bunks: 2\n  : Luxury: Yes\n";
    assert(expectedOutput == out.str()); // Match the output with the expected output

    // Also print the object to the screen for better clarity
    cout << BookingClass::FirstClass::Type() << endl;
}

template<>
void BookingClass::AC3Tier::UnitTest() {
    // Testing the Type() function (constructor automatically gets tested during this)
    // To test the singleton behaviour, we compare the addresses of the objects after calling Type() for the first and second time
    const BookingClass::AC3Tier* firstPointer = &BookingClass::AC3Tier::Type(); // First Call
    const BookingClass::AC3Tier* secondPointer = &BookingClass::AC3Tier::Type(); // Second Call
    assert(firstPointer == secondPointer); // Compare both the addresses for equality

    assert(2.50 == BookingClass::AC3Tier::Type().GetLoadFactor()); // Testing GetLoadFactor()
    assert("AC 3 Tier" == BookingClass::AC3Tier::Type().GetName()); // Testing GetName()
    assert(false == BookingClass::AC3Tier::Type().IsSitting()); // Testing IsSitting()
    assert(true == BookingClass::AC3Tier::Type().IsAC()); // Testing IsAC()
    assert(3 == BookingClass::AC3Tier::Type().GetNumberOfTiers()); // Testing GetNumberOfTiers()
    assert(false == BookingClass::AC3Tier::Type().IsLuxury()); // Testing IsLuxury()
    assert(40.00 == BookingClass::AC3Tier::Type().GetReservationCharge());
    assert(0.30 == BookingClass::AC3Tier::Type().GetTatkalLoadFactor());
    assert(300.00 == BookingClass::AC3Tier::Type().GetMinTatkalCharge());
    assert(400.00 == BookingClass::AC3Tier::Type().GetMaxTatkalCharge());
    assert(500 == BookingClass::AC3Tier::Type().GetMinTatkalDistance());


    // Testing the ostream operator
    stringstream out;
    out << BookingClass::AC3Tier::Type();

    string expectedOutput = "Travel Class = AC 3 Tier\n  : Mode: Sleeping\n  : Comfort: AC\n  : Bunks: 3\n  : Luxury: No\n";
    assert(expectedOutput == out.str()); // Match the output with the expected output

    // Also print the object to the screen for better clarity
    cout << BookingClass::AC3Tier::Type() << endl;
}

template<>
void BookingClass::ACChairCar::UnitTest() {
    // Testing the Type() function (constructor automatically gets tested during this)
    // To test the singleton behaviour, we compare the addresses of the objects after calling Type() for the first and second time
    const BookingClass::ACChairCar* firstPointer = &BookingClass::ACChairCar::Type(); // First Call
    const BookingClass::ACChairCar* secondPointer = &BookingClass::ACChairCar::Type(); // Second Call
    assert(firstPointer == secondPointer); // Compare both the addresses for equality

    assert(2.00 == BookingClass::ACChairCar::Type().GetLoadFactor()); // Testing GetLoadFactor()
    assert("AC Chair Car" == BookingClass::ACChairCar::Type().GetName()); // Testing GetName()
    assert(true == BookingClass::ACChairCar::Type().IsSitting()); // Testing IsSitting()
    assert(true == BookingClass::ACChairCar::Type().IsAC()); // Testing IsAC()
    assert(0 == BookingClass::ACChairCar::Type().GetNumberOfTiers()); // Testing GetNumberOfTiers()
    assert(false == BookingClass::ACChairCar::Type().IsLuxury()); // Testing IsLuxury()
    assert(40.00 == BookingClass::ACChairCar::Type().GetReservationCharge());
    assert(0.30 == BookingClass::ACChairCar::Type().GetTatkalLoadFactor());
    assert(125.00 == BookingClass::ACChairCar::Type().GetMinTatkalCharge());
    assert(225.00 == BookingClass::ACChairCar::Type().GetMaxTatkalCharge());
    assert(250 == BookingClass::ACChairCar::Type().GetMinTatkalDistance());


    // Testing the ostream operator
    stringstream out;
    out << BookingClass::ACChairCar::Type();

    string expectedOutput = "Travel Class = AC Chair Car\n  : Mode: Sitting\n  : Comfort: AC\n  : Bunks: 0\n  : Luxury: No\n";
    assert(expectedOutput == out.str()); // Match the output with the expected output

    // Also print the object to the screen for better clarity
    cout << BookingClass::ACChairCar::Type() << endl;
}

template<>
void BookingClass::Sleeper::UnitTest() {
    // Testing the Type() function (constructor automatically gets tested during this)
    // To test the singleton behaviour, we compare the addresses of the objects after calling Type() for the first and second time
    const BookingClass::Sleeper* firstPointer = &BookingClass::Sleeper::Type(); // First Call
    const BookingClass::Sleeper* secondPointer = &BookingClass::Sleeper::Type(); // Second Call
    assert(firstPointer == secondPointer); // Compare both the addresses for equality

    assert(1.00 == BookingClass::Sleeper::Type().GetLoadFactor()); // Testing GetLoadFactor()
    assert("Sleeper" == BookingClass::Sleeper::Type().GetName()); // Testing GetName()
    assert(false == BookingClass::Sleeper::Type().IsSitting()); // Testing IsSitting()
    assert(false == BookingClass::Sleeper::Type().IsAC()); // Testing IsAC()
    assert(3 == BookingClass::Sleeper::Type().GetNumberOfTiers()); // Testing GetNumberOfTiers()
    assert(false == BookingClass::Sleeper::Type().IsLuxury()); // Testing IsLuxury()
    assert(20.00 == BookingClass::Sleeper::Type().GetReservationCharge());
    assert(0.30 == BookingClass::Sleeper::Type().GetTatkalLoadFactor());
    assert(100.00 == BookingClass::Sleeper::Type().GetMinTatkalCharge());
    assert(200.00 == BookingClass::Sleeper::Type().GetMaxTatkalCharge());
    assert(500 == BookingClass::Sleeper::Type().GetMinTatkalDistance());


    // Testing the ostream operator
    stringstream out;
    out << BookingClass::Sleeper::Type();

    string expectedOutput = "Travel Class = Sleeper\n  : Mode: Sleeping\n  : Comfort: Non-AC\n  : Bunks: 3\n  : Luxury: No\n";
    assert(expectedOutput == out.str()); // Match the output with the expected output

    // Also print the object to the screen for better clarity
    cout << BookingClass::Sleeper::Type() << endl;
}

template<>
void BookingClass::SecondSitting::UnitTest() {
    // Testing the Type() function (constructor automatically gets tested during this)
    // To test the singleton behaviour, we compare the addresses of the objects after calling Type() for the first and second time
    const BookingClass::SecondSitting* firstPointer = &BookingClass::SecondSitting::Type(); // First Call
    const BookingClass::SecondSitting* secondPointer = &BookingClass::SecondSitting::Type(); // Second Call
    assert(firstPointer == secondPointer); // Compare both the addresses for equality

    assert(0.60 == BookingClass::SecondSitting::Type().GetLoadFactor()); // Testing GetLoadFactor()
    assert("Second Sitting" == BookingClass::SecondSitting::Type().GetName()); // Testing GetName()
    assert(true == BookingClass::SecondSitting::Type().IsSitting()); // Testing IsSitting()
    assert(false == BookingClass::SecondSitting::Type().IsAC()); // Testing IsAC()
    assert(0 == BookingClass::SecondSitting::Type().GetNumberOfTiers()); // Testing GetNumberOfTiers()
    assert(false == BookingClass::SecondSitting::Type().IsLuxury()); // Testing IsLuxury()
    assert(15.00 == BookingClass::SecondSitting::Type().GetReservationCharge());
    assert(0.10 == BookingClass::SecondSitting::Type().GetTatkalLoadFactor());
    assert(10.00 == BookingClass::SecondSitting::Type().GetMinTatkalCharge());
    assert(15.00 == BookingClass::SecondSitting::Type().GetMaxTatkalCharge());
    assert(100 == BookingClass::SecondSitting::Type().GetMinTatkalDistance());


    // Testing the ostream operator
    stringstream out;
    out << BookingClass::SecondSitting::Type();

    string expectedOutput = "Travel Class = Second Sitting\n  : Mode: Sitting\n  : Comfort: Non-AC\n  : Bunks: 0\n  : Luxury: No\n";
    assert(expectedOutput == out.str()); // Match the output with the expected output

    // Also print the object to the screen for better clarity
    cout << BookingClass::SecondSitting::Type() << endl;
}


int main() {
    BookingClass::ACFirstClass::UnitTest();
    BookingClass::ExecutiveChairCar::UnitTest();
    BookingClass::AC2Tier::UnitTest();
    BookingClass::FirstClass::UnitTest();
    BookingClass::AC3Tier::UnitTest();
    BookingClass::ACChairCar::UnitTest();
    BookingClass::Sleeper::UnitTest();
    BookingClass::SecondSitting::UnitTest();

    return 0;
}
