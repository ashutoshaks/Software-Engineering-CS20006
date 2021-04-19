/*
    CS20006 Assignment 3
    BookingClasses.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

// Source File for the hierarchy of booking classes

// Including project header files
#include "BookingClasses.h"

// The values of the static constants of this hierarchy of class can change from time to time.
// Hence, they should be initialized in the application space.

// BookingClasses
BookingClasses::BookingClasses(const string& name, const bool isAC, const bool isLuxury) : name_(name), isAC_(isAC), isLuxury_(isLuxury)
{}

BookingClasses::~BookingClasses()
{}

// Function bodies of the non - polymorphic functions
string BookingClasses::GetName() const
{
    return name_;
}

bool BookingClasses::IsAC() const
{
    return isAC_;
}

bool BookingClasses::IsLuxury() const
{
    return isLuxury_;
}

ostream& operator<<(ostream& os, const BookingClasses& bookingClass)
{
    os << "Travel Class = " << bookingClass.GetName() << endl;
    os << "  : Mode: " << (bookingClass.IsSitting() ? "Sitting" : "Sleeping") << endl;
    os << "  : Comfort: " << (bookingClass.IsAC() ? "AC" : "Non-AC") << endl;
    os << "  : Bunks: " << bookingClass.GetNumberOfTiers() << endl;
    os << "  : Luxury: " << (bookingClass.IsLuxury() ? "Yes" : "No") << endl;
    return os;
}

// Berth
Berth::Berth(const string& name, const bool isAC, const bool isLuxury) : BookingClasses(name, isAC, isLuxury)
{}

Berth::~Berth()
{}

// Define the isSitting() function as it is false for all booking classes having sleeping berths
bool Berth::IsSitting() const
{
    return false;
}

// Seat
Seat::Seat(const string& name, const bool isAC, const bool isLuxury) : BookingClasses(name, isAC, isLuxury)
{}

Seat::~Seat()
{}

// Define the isSitting() function as it is true for all booking classes having seats
bool Seat::IsSitting() const
{
    return true;
}

// Define the GetNumberOfTiers() function as 0 for all booking classes having seats
int Seat::GetNumberOfTiers() const
{
    return 0;
}

// Tiers2
Tiers2::Tiers2(const string& name, const bool isAC, const bool isLuxury) : Berth(name, isAC, isLuxury)
{}

Tiers2::~Tiers2()
{}

// Define the GetNumberOfTiers() function as 2
int Tiers2::GetNumberOfTiers() const
{
    return 2;
}

// Tiers3
Tiers3::Tiers3(const string& name, const bool isAC, const bool isLuxury) : Berth(name, isAC, isLuxury)
{}

Tiers3::~Tiers3()
{}

// Define the GetNumberOfTiers() function as 3
int Tiers3::GetNumberOfTiers() const
{
    return 3;
}

// ACFirstClass
ACFirstClass::ACFirstClass() : Tiers2("AC First Class", true, true) // Call the appropriate constructor with the appropriate attribute values
{}

ACFirstClass::~ACFirstClass()
{}

const ACFirstClass& ACFirstClass::Type()
{
    static const ACFirstClass theObj;
    return theObj;
}

double ACFirstClass::GetLoadFactor() const
{
    return ACFirstClass::sLoadFactor;
}

// AC2Tier
AC2Tier::AC2Tier() : Tiers2("AC 2 Tier", true, false) // Call the appropriate constructor with the appropriate attribute values
{}

AC2Tier::~AC2Tier()
{}

const AC2Tier& AC2Tier::Type()
{
    static const AC2Tier theObj;
    return theObj;
}

double AC2Tier::GetLoadFactor() const
{
    return AC2Tier::sLoadFactor;
}

// FirstClass
FirstClass::FirstClass() : Tiers2("First Class", false, true) // Call the appropriate constructor with the appropriate attribute values
{}

FirstClass::~FirstClass()
{}

const FirstClass& FirstClass::Type()
{
    static const FirstClass theObj;
    return theObj;
}

double FirstClass::GetLoadFactor() const
{
    return FirstClass::sLoadFactor;
}

// AC3Tier
AC3Tier::AC3Tier() : Tiers3("AC 3 Tier", true, false) // Call the appropriate constructor with the appropriate attribute values
{}

AC3Tier::~AC3Tier()
{}

const AC3Tier& AC3Tier::Type()
{
    static const AC3Tier theObj;
    return theObj;
}

double AC3Tier::GetLoadFactor() const
{
    return AC3Tier::sLoadFactor;
}

// ACChairCar
ACChairCar::ACChairCar() : Seat("AC Chair Car", true, false) // Call the appropriate constructor with the appropriate attribute values
{}

ACChairCar::~ACChairCar()
{}

const ACChairCar& ACChairCar::Type()
{
    static const ACChairCar theObj;
    return theObj;
}

double ACChairCar::GetLoadFactor() const
{
    return ACChairCar::sLoadFactor;
}

// Sleeper
Sleeper::Sleeper() : Tiers3("Sleeper", false, false) // Call the appropriate constructor with the appropriate attribute values
{}

Sleeper::~Sleeper()
{}

const Sleeper& Sleeper::Type()
{
    static const Sleeper theObj;
    return theObj;
}

double Sleeper::GetLoadFactor() const
{
    return Sleeper::sLoadFactor;
}

// SecondSitting
SecondSitting::SecondSitting() : Seat("Second Sitting", false, false) // Call the appropriate constructor with the appropriate attribute values
{}

SecondSitting::~SecondSitting()
{}

const SecondSitting& SecondSitting::Type()
{
    static const SecondSitting theObj;
    return theObj;
}

double SecondSitting::GetLoadFactor() const
{
    return SecondSitting::sLoadFactor;
}