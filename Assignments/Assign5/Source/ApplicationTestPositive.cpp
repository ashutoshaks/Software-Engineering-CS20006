/*
    CS20006 Assignment 5
    ApplicationTestPositive.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

// Positive Application Test File for the entire project

// Including project header files
#include "Station.h"
#include "Railways.h"
#include "Date.h"
#include "Gender.h"
#include "Name.h"
#include "Passenger.h"
#include "BookingClass.h"
#include "BookingCategory.h"
#include "Concession.h"
#include "Booking.h"

// Initializing static constants
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

const double Booking::sBaseFarePerKM = 0.5;


// Test Application for booking
void BookingApplication() {

    // General Booking
    const Passenger* p1 = NULL;
    try {
        p1 = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", Gender::Male::Type(), "845626586698", "9999888877");
    } catch(Bad_Passenger& e) {
        cout << "Could not create Passenger\n\n";
    }
    Booking* b1 = NULL;
    try {
        b1 = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::AC3Tier::Type(), BookingCategory::General::Type(), p1);
    } catch(Bad_Booking& e) {
        cout << "Could not create Booking\n\n";
    }

    // Ladies Booking 
    const Passenger* p2 = NULL;
    try {
        p2 = Passenger::CreatePassenger("Arya", "Kumari", "Singh", "11/07/1992", Gender::Female::Type(), "745634695243", "9763425843");
    } catch(Bad_Passenger& e) {
        cout << "Could not create Passenger\n\n";
    }
    Booking* b2 = NULL;
    try {
        b2 = Booking::ReserveBooking("Kolkata", "Mumbai", "15/04/2021", BookingClass::ExecutiveChairCar::Type(), BookingCategory::Ladies::Type(), p2);
    } catch(Bad_Booking& e) {
        cout << "Could not create Booking\n\n";
    }

    // Senior Citizen Male booking
    const Passenger* p3 = NULL;
    try {
        p3 = Passenger::CreatePassenger("Manku", "", "Barnawal", "11/03/1950", Gender::Male::Type(), "652147896325", "9874562130");
    } catch(Bad_Passenger& e) {
        cout << "Could not create Passenger\n\n";
    }
    Booking* b3 = NULL;
    try {
        b3 = Booking::ReserveBooking("Bangalore", "Kolkata", "15/04/2021", BookingClass::AC2Tier::Type(), BookingCategory::SeniorCitizen::Type(), p3);
    } catch(Bad_Booking& e) {
        cout << "Could not create Booking\n\n";
    }

    // Senior Citizen Female booking
    const Passenger* p4 = NULL;
    try {
        p4 = Passenger::CreatePassenger("Vashisth", "", "Garg", "11/03/1961", Gender::Female::Type(), "100011111111", "9876543210");
    } catch(Bad_Passenger& e) {
        cout << "Could not create Passenger\n\n";
    }
    Booking* b4 = NULL;
    try {
        b4 = Booking::ReserveBooking("Chennai", "Bangalore", "15/02/2022", BookingClass::FirstClass::Type(), BookingCategory::SeniorCitizen::Type(), p4);
    } catch(Bad_Booking& e) {
        cout << "Could not create Booking\n\n";
    }

    // Tatkal for normal person
    const Passenger* p5 = NULL;
    try {
        p5 = Passenger::CreatePassenger("Varun", "", "Phogat", "11/03/2002", Gender::Male::Type(), "632547896259", "8521479632");
    } catch(Bad_Passenger& e) {
        cout << "Could not create Passenger\n\n";
    }
    Booking* b5 = NULL;
    try {
        b5 = Booking::ReserveBooking("Delhi", "Mumbai", "10/04/2021", BookingClass::ExecutiveChairCar::Type(), BookingCategory::Tatkal::Type(), p5);
    } catch(Bad_Booking& e) {
        cout << "Could not create Booking\n\n";
    }

    // Premium Tatakal for person who cannot avail concession now
    const Passenger* p6 = NULL;
    try {
        p6 = Passenger::CreatePassenger("Harish", "Vardhan", "Mundhra", "11/03/2002", Gender::Male::Type(), "100011111111", "8761669365", &Divyaang::Blind::Type(), "0221");
    } catch(Bad_Passenger& e) {
        cout << "Could not create Passenger\n\n";
    }
    Booking* b6 = NULL;
    try {
        b6 = Booking::ReserveBooking("Delhi", "Kolkata", "10/04/2021", BookingClass::ExecutiveChairCar::Type(), BookingCategory::PremiumTatkal::Type(), p6);
    } catch(Bad_Booking& e) {
        cout << "Could not create Booking\n\n";
    }

    // Booking for Divyaang - Blind
    const Passenger* p7 = NULL;
    try {
        p7 = Passenger::CreatePassenger("Manish", "", "Pandey", "11/03/2002", Gender::Male::Type(), "100011111111", "", &Divyaang::Blind::Type(), "012");
    } catch(Bad_Passenger& e) {
        cout << "Could not create Passenger\n\n";
    }
    Booking* b7 = NULL;
    try {
        b7 = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::AC3Tier::Type(), Divyaang::Blind::Type(), p7);
    } catch(Bad_Booking& e) {
       cout << "Could not create Booking\n\n";
    }

    // Booking for Divyaang - Orthopedically Handicapped
    const Passenger* p8 = NULL;
    try {
        p8 = Passenger::CreatePassenger("Rakesh", "", "Chandra", "11/03/2002", Gender::Male::Type(), "100011111111", "7456325896", &Divyaang::OrthoHandicapped::Type(), "007");
    } catch(Bad_Passenger& e) {
        cout << "Could not create Passenger\n\n";
    }
    Booking* b8 = NULL;
    try {
        b8 = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::AC3Tier::Type(), Divyaang::OrthoHandicapped::Type(), p8);
    } catch(Bad_Booking& e) {
        cout << "Could not create Booking\n\n";
    }

    // Booking for Divyaang - Cancer Patient
    const Passenger* p9 = NULL;
    try {
        p9 = Passenger::CreatePassenger("Laxman", "", "Mittal", "11/03/2002", Gender::Male::Type(), "100011111111", "", &Divyaang::Cancer::Type(), "125");
    } catch(Bad_Passenger& e) {
        cout << "Could not create Passenger\n\n";
    }
    Booking* b9 = NULL;
    try {
        b9 = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::AC3Tier::Type(), Divyaang::Cancer::Type(), p9);
    } catch(Bad_Booking& e) {
        cout << "Could not create Booking\n\n";
    }

    // Booking for Divyaang - TB Patient
    const Passenger* p10 = NULL;
    try {
        p10 = Passenger::CreatePassenger("Ishan", "Chandra", "Pandey", "11/03/2002", Gender::Male::Type(), "100011111111", "6823457896", &Divyaang::TB::Type(), "215");
    } catch(Bad_Passenger& e) {
        cout << "Could not create Passenger\n\n";
    }
    Booking* b10 = NULL;
    try {
        b10 = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::AC3Tier::Type(), Divyaang::TB::Type(), p10);
    } catch(Bad_Booking& e) {
        cout << "Could not create Booking\n\n";
    }

    vector<Booking*>::iterator it;
    for(it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) {
        cout << *(*it) << "\n\n\n";
    }
}
    
int main() {
    BookingApplication();

    return 0;
}