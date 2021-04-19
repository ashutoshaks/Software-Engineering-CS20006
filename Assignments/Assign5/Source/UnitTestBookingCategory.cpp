/*
    CS20006 Assignment 5
    UnitTestBooking.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

/*
    COMPILATION AND BUILD COMMANDS :
    g++ -std=c++11 Station.cpp Railways.cpp Date.cpp Gender.cpp Name.cpp Passenger.cpp BookingClass.cpp BookingCategory.cpp Concession.cpp Booking.cpp Exceptions.cpp UnitTestBookingCategory.cpp -o test
    ./test
*/

// Unit Testing File for class BookingCategory

// Including project header files
#include "BookingCategory.h"
#include "BookingClass.h"
#include "Booking.h"
#include "Exceptions.h"

// C++ Headers
#include <cassert>
#include <sstream>


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


const double Booking::sBaseFarePerKM = 0.50;


void BookingCategory::UnitTestBookingCategory() {

    // General
    assert("General" == BookingCategory::General::Type().GetName());
    try {
        const Passenger* p = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", Gender::Male::Type(), "012345678901", "9988774567");
        assert(true == BookingCategory::General::Type().IsEligible(*p));
    } catch(Bad_Passenger) {
        // Already handled
    }

    // Ladies
    assert("Ladies" == BookingCategory::Ladies::Type().GetName());
    try {
        const Passenger* p = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", Gender::Female::Type(), "012345678901", "9988774567");
        assert(true == BookingCategory::Ladies::Type().IsEligible(*p));
    } catch(Bad_Passenger) {
        // Already handled
    }

    try {
        const Passenger* p = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", Gender::Male::Type(), "012345678901", "9988774567");
        assert(false == BookingCategory::Ladies::Type().IsEligible(*p));
    } catch(Bad_Passenger) {
        // Already handled
    }

    // Senior Citizen
    assert("Senior Citizen" == BookingCategory::SeniorCitizen::Type().GetName());
    try {
        const Passenger* p = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/1950", Gender::Male::Type(), "012345678901", "9988774567");
        assert(true == BookingCategory::SeniorCitizen::Type().IsEligible(*p));
    } catch(Bad_Passenger) {
        // Already handled
    }

    try {
        const Passenger* p = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", Gender::Male::Type(), "012345678901", "9988774567");
        assert(false == BookingCategory::SeniorCitizen::Type().IsEligible(*p));
    } catch(Bad_Passenger) {
        // Already handled
    }

    // Tatkal
    assert("Tatkal" == BookingCategory::Tatkal::Type().GetName());
    try {
        const Passenger* p = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", Gender::Male::Type(), "012345678901", "9988774567");
        assert(true == BookingCategory::Tatkal::Type().IsEligible(*p));
    } catch(Bad_Passenger) {
        // Already handled
    }

    // Premium Tatkal
    assert("Premium Tatkal" == BookingCategory::PremiumTatkal::Type().GetName());
    try {
        const Passenger* p = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", Gender::Male::Type(), "012345678901", "9988774567");
        assert(true == BookingCategory::PremiumTatkal::Type().IsEligible(*p));
    } catch(Bad_Passenger) {
        // Already handled
    }


    // Divyaang - Blind
    assert("Divyaang - Blind" == Divyaang::Blind::Type().GetName());
    try {
        const Passenger* p = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", Gender::Male::Type(), "012345678901", "9988774567", &Divyaang::Blind::Type(), "012");
        assert(true == Divyaang::Blind::Type().IsEligible(*p));
    } catch(Bad_Passenger) {
        // Already handled
    }

    try {
        const Passenger* p = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", Gender::Male::Type(), "012345678901", "9988774567");
        assert(false == Divyaang::Blind::Type().IsEligible(*p));
    } catch(Bad_Passenger) {
        // Already handled
    }

    // Divyaang - Orthopaedically Handicapped
    assert("Divyaang - Orthopaedically Handicapped" == Divyaang::OrthoHandicapped::Type().GetName());
    try {
        const Passenger* p = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", Gender::Male::Type(), "012345678901", "9988774567", &Divyaang::OrthoHandicapped::Type(), "012");
        assert(true == Divyaang::OrthoHandicapped::Type().IsEligible(*p));
    } catch(Bad_Passenger) {
        // Already handled
    }

    try {
        const Passenger* p = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", Gender::Male::Type(), "012345678901", "9988774567");
        assert(false == Divyaang::OrthoHandicapped::Type().IsEligible(*p));
    } catch(Bad_Passenger) {
        // Already handled
    }

    // Divyaang - Cancer
    assert("Divyaang - Cancer" == Divyaang::Cancer::Type().GetName());
    try {
        const Passenger* p = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", Gender::Male::Type(), "012345678901", "9988774567", &Divyaang::Cancer::Type(), "012");
        assert(true == Divyaang::Cancer::Type().IsEligible(*p));
    } catch(Bad_Passenger) {
        // Already handled
    }

    try {
        const Passenger* p = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", Gender::Male::Type(), "012345678901", "9988774567");
        assert(false == Divyaang::Cancer::Type().IsEligible(*p));
    } catch(Bad_Passenger) {
        // Already handled
    }

    // Divyaang - TB
    assert("Divyaang - TB" == Divyaang::TB::Type().GetName());
    try {
        const Passenger* p = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", Gender::Male::Type(), "012345678901", "9988774567", &Divyaang::TB::Type(), "012");
        assert(true == Divyaang::TB::Type().IsEligible(*p));
    } catch(Bad_Passenger) {
        // Already handled
    }

    try {
        const Passenger* p = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", Gender::Male::Type(), "012345678901", "9988774567");
        assert(false == Divyaang::TB::Type().IsEligible(*p));
    } catch(Bad_Passenger) {
        // Already handled
    }
}

int main() {
    BookingCategory::UnitTestBookingCategory();

    return 0;
}