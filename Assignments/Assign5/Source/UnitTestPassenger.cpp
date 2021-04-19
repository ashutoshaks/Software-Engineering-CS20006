/*
    CS20006 Assignment 5
    UnitTestPassenger.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

/*
    COMPILATION AND BUILD COMMANDS :
    g++ -std=c++11 Station.cpp Railways.cpp Date.cpp Gender.cpp Name.cpp Passenger.cpp BookingClass.cpp BookingCategory.cpp Concession.cpp Booking.cpp Exceptions.cpp UnitTestPassenger.cpp -o test
    ./test
*/

// Unit Testing File for class Passenger

// Including project header files
#include "Passenger.h"
#include "Exceptions.h"
#include "BookingCategory.h"
#include "BookingClass.h"
#include "Booking.h"

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


void Passenger::UnitTestPassenger() {

    /*
    * POSITIVE TEST CASES
    */

    stringstream out;

    try {
        const Passenger* p1 = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", Gender::Male::Type(), "012345678901", "9988774567", &Divyaang::Blind::Type(), "012");
        assert(Date(11, 03, 2002) == p1 -> dateOfBirth_);
        assert(Gender::IsMale(p1 -> gender_));
        assert("012345678901" == p1 -> aadhaar_);
        assert("9988774567" == p1 -> mobile_);
        assert(&Divyaang::Blind::Type() == p1 -> disabilityType_);
        assert("012" == p1 -> disabilityID_);

        assert(Date(11, 03, 2002) == p1 -> GetDateOfBirth());

        assert(Gender::IsMale(p1 -> GetGender()));

        assert(&Divyaang::Blind::Type() == p1 -> GetDisability());

        out << (*p1);
        string expectedOutput = "Name: Ashutosh Kumar Singh\nDate Of Birth: Mon, 11/Mar/2002\nGender: Male\n"
                                "Aadhaar: 012345678901\nMobile: 9988774567\nDisability Type: Blind\nDisability ID: 012\n";
        assert(expectedOutput == out.str());
        cout << (*p1) << endl;
    } catch (Bad_Passenger& e) {
        cout << e.what() << endl;
    }

    try {
        const Passenger* p2 = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", Gender::Male::Type(), "012345678901");
        assert(Date(11, 03, 2002) == p2 -> dateOfBirth_);
        assert(Gender::IsMale(p2 -> gender_));
        assert("012345678901" == p2 -> aadhaar_);
        cout << (*p2) << endl;
    } catch (Bad_Passenger& e) {
        cout << e.what() << endl;
    }


    /*
    * NEGATIVE TEST CASES
    */

    try {
        const Passenger* p3 = Passenger::CreatePassenger("", "Kumar", "", "11/03/2002", Gender::Male::Type(), "012345678901", "9988774567", &Divyaang::Blind::Type(), "012");
        cout << (*p3) << endl;
    } catch (Bad_Passenger& e) {
        // Appropriate error message will already have been printed
    }

    try {
        const Passenger* p4 = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2030", Gender::Male::Type(), "012345678901", "9988774567", &Divyaang::Blind::Type(), "012");
        cout << (*p4) << endl;
    } catch (Bad_Passenger& e) {
        // Appropriate error message will already have been printed
    }

    try {
        const Passenger* p4 = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", Gender::Male::Type(), "007", "9988774567", &Divyaang::Blind::Type(), "012");
        cout << (*p4) << endl;
    } catch (Bad_Passenger& e) {
        // Appropriate error message will already have been printed
    }

    try {
        const Passenger* p4 = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", Gender::Male::Type(), "012345678901", "007", &Divyaang::Blind::Type(), "012");
        cout << (*p4) << endl;
    } catch (Bad_Passenger& e) {
        // Appropriate error message will already have been printed
    }
}

int main() {
    Passenger::UnitTestPassenger();

    return 0;
}