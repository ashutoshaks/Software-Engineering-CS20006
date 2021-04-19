/*
    CS20006 Assignment 3
    BookingClass.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

#include "BookingClass.h"

// Private
template<> const string BookingClass::ACFirstClass::sName = "AC First Class";
template<> const bool BookingClass::ACFirstClass::sIsSitting = false;
template<> const bool BookingClass::ACFirstClass::sIsAC = true;
template<> const int BookingClass::ACFirstClass::sNumberOfTiers = 2;

template<> const string BookingClass::ExecutiveChairCar::sName = "Executive Chair Car";
template<> const bool BookingClass::ExecutiveChairCar::sIsSitting = true;
template<> const bool BookingClass::ExecutiveChairCar::sIsAC = true;
template<> const int BookingClass::ExecutiveChairCar::sNumberOfTiers = 0;

template<> const string BookingClass::AC2Tier::sName = "AC 2 Tier";
template<> const bool BookingClass::AC2Tier::sIsSitting = false;
template<> const bool BookingClass::AC2Tier::sIsAC = true;
template<> const int BookingClass::AC2Tier::sNumberOfTiers = 2;

template<> const string BookingClass::FirstClass::sName = "First Class";
template<> const bool BookingClass::FirstClass::sIsSitting = false;
template<> const bool BookingClass::FirstClass::sIsAC = false;
template<> const int BookingClass::FirstClass::sNumberOfTiers = 2;

template<> const string BookingClass::AC3Tier::sName = "AC 3 Tier";
template<> const bool BookingClass::AC3Tier::sIsSitting = false;
template<> const bool BookingClass::AC3Tier::sIsAC = true;
template<> const int BookingClass::AC3Tier::sNumberOfTiers = 3;

template<> const string BookingClass::ACChairCar::sName = "AC Chair Car";
template<> const bool BookingClass::ACChairCar::sIsSitting = true;
template<> const bool BookingClass::ACChairCar::sIsAC = true;
template<> const int BookingClass::ACChairCar::sNumberOfTiers = 0;

template<> const string BookingClass::Sleeper::sName = "Sleeper";
template<> const bool BookingClass::Sleeper::sIsSitting = false;
template<> const bool BookingClass::Sleeper::sIsAC = false;
template<> const int BookingClass::Sleeper::sNumberOfTiers = 3;

template<> const string BookingClass::SecondSitting::sName = "Second Sitting";
template<> const bool BookingClass::SecondSitting::sIsSitting = true;
template<> const bool BookingClass::SecondSitting::sIsAC = false;
template<> const int BookingClass::SecondSitting::sNumberOfTiers = 0;


// Public
// template<> const double BookingClass::ACFirstClass::sLoadFactor = 6.50;
// template<> const bool BookingClass::ACFirstClass::sIsLuxury = true;
// template<> const double BookingClass::ACFirstClass::sReservationCharge = 60.00;
// template<> const double BookingClass::ACFirstClass::sTatkalLoadFactor = 0.30;
// template<> const double BookingClass::ACFirstClass::sMinTatkalCharge = 400.00;
// template<> const double BookingClass::ACFirstClass::sMaxTatkalCharge = 500.00;
// template<> const int BookingClass::ACFirstClass::sMinTatkalDistance = 500;

// template<> const double BookingClass::ExecutiveChairCar::sLoadFactor = 5.00;
// template<> const bool BookingClass::ExecutiveChairCar::sIsLuxury = true;
// template<> const double BookingClass::ExecutiveChairCar::sReservationCharge = 60.00;
// template<> const double BookingClass::ExecutiveChairCar::sTatkalLoadFactor = 0.30;
// template<> const double BookingClass::ExecutiveChairCar::sMinTatkalCharge = 400.00;
// template<> const double BookingClass::ExecutiveChairCar::sMaxTatkalCharge = 500.00;
// template<> const int BookingClass::ExecutiveChairCar::sMinTatkalDistance = 250;

// template<> const double BookingClass::AC2Tier::sLoadFactor = 4.00;
// template<> const bool BookingClass::AC2Tier::sIsLuxury = false;
// template<> const double BookingClass::AC2Tier::sReservationCharge = 50.00;
// template<> const double BookingClass::AC2Tier::sTatkalLoadFactor = 0.30;
// template<> const double BookingClass::AC2Tier::sMinTatkalCharge = 400.00;
// template<> const double BookingClass::AC2Tier::sMaxTatkalCharge = 500.00;
// template<> const int BookingClass::AC2Tier::sMinTatkalDistance = 500;

// template<> const double BookingClass::FirstClass::sLoadFactor = 3.00;
// template<> const bool BookingClass::FirstClass::sIsLuxury = true;
// template<> const double BookingClass::FirstClass::sReservationCharge = 50.00;
// template<> const double BookingClass::FirstClass::sTatkalLoadFactor = 0.30;
// template<> const double BookingClass::FirstClass::sMinTatkalCharge = 400.00;
// template<> const double BookingClass::FirstClass::sMaxTatkalCharge = 500.00;
// template<> const int BookingClass::FirstClass::sMinTatkalDistance = 500;

// template<> const double BookingClass::AC3Tier::sLoadFactor = 2.50;
// template<> const bool BookingClass::AC3Tier::sIsLuxury = false;
// template<> const double BookingClass::AC3Tier::sReservationCharge = 40.00;
// template<> const double BookingClass::AC3Tier::sTatkalLoadFactor = 0.30;
// template<> const double BookingClass::AC3Tier::sMinTatkalCharge = 300.00;
// template<> const double BookingClass::AC3Tier::sMaxTatkalCharge = 400.00;
// template<> const int BookingClass::AC3Tier::sMinTatkalDistance = 500;

// template<> const double BookingClass::ACChairCar::sLoadFactor = 2.00;
// template<> const bool BookingClass::ACChairCar::sIsLuxury = false;
// template<> const double BookingClass::ACChairCar::sReservationCharge = 40.00;
// template<> const double BookingClass::ACChairCar::sTatkalLoadFactor = 0.30;
// template<> const double BookingClass::ACChairCar::sMinTatkalCharge = 125.00;
// template<> const double BookingClass::ACChairCar::sMaxTatkalCharge = 225.00;
// template<> const int BookingClass::ACChairCar::sMinTatkalDistance = 250;

// template<> const double BookingClass::Sleeper::sLoadFactor = 1.00;
// template<> const bool BookingClass::Sleeper::sIsLuxury = false;
// template<> const double BookingClass::Sleeper::sReservationCharge = 20.00;
// template<> const double BookingClass::Sleeper::sTatkalLoadFactor = 0.30;
// template<> const double BookingClass::Sleeper::sMinTatkalCharge = 100.00;
// template<> const double BookingClass::Sleeper::sMaxTatkalCharge = 200.00;
// template<> const int BookingClass::Sleeper::sMinTatkalDistance = 500;

// template<> const double BookingClass::SecondSitting::sLoadFactor = 0.60;
// template<> const bool BookingClass::SecondSitting::sIsLuxury = false;
// template<> const double BookingClass::SecondSitting::sReservationCharge = 15.00;
// template<> const double BookingClass::SecondSitting::sTatkalLoadFactor = 0.10;
// template<> const double BookingClass::SecondSitting::sMinTatkalCharge = 10.00;
// template<> const double BookingClass::SecondSitting::sMaxTatkalCharge = 15.00;
// template<> const int BookingClass::SecondSitting::sMinTatkalDistance = 100;


ostream& operator<<(ostream& os, const BookingClass& bookingClass) {
    os << "Travel Class = " << bookingClass.GetName() << endl;
    os << "  : Mode: " << (bookingClass.IsSitting() ? "Sitting" : "Sleeping") << endl;
    os << "  : Comfort: " << (bookingClass.IsAC() ? "AC" : "Non-AC") << endl;
    os << "  : Bunks: " << bookingClass.GetNumberOfTiers() << endl;
    os << "  : Luxury: " << (bookingClass.IsLuxury() ? "Yes" : "No") << endl;
    return os;
}