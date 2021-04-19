/*
    CS20006 Assignment 5
    ApplicationTestNegative.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

// Negative Application Test File for the entire project

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

    // From station is invalid
    const Passenger* p1 = NULL;
    try {
        p1 = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", 
                        Gender::Male::Type(), "100011111111", "9999888877");
    } catch(Bad_Passenger& e) {
        cout << "Could not create Passenger\n\n";
    }
    Booking* b1 = NULL;
    try {
        b1 = Booking::ReserveBooking("Dilli", "Mumbai", "15/04/2021", BookingClass::AC3Tier::Type(), 
                                BookingCategory::General::Type(), p1);
    } catch(Bad_Booking& e) {
        cout << "Could not create Booking\n\n";
    }

    // To station is invalid
    const Passenger* p2 = NULL;
    try {
        p2 = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", 
                        Gender::Male::Type(), "100011111111", "9999888877");
    } catch(Bad_Passenger& e) {
        cout << "Could not create Passenger\n\n";
    }
    Booking* b2 = NULL;
    try {
        b2 = Booking::ReserveBooking("Delhi", "Bombay", "15/04/2021", BookingClass::AC3Tier::Type(), 
                                BookingCategory::General::Type(), p2);
    } catch(Bad_Booking& e) {
        cout << "Could not create Booking\n\n";
    }

    // From and To station are the same
    const Passenger* p3 = NULL;
    try {
        p3 = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", 
                        Gender::Male::Type(), "100011111111", "9999888877");
    } catch(Bad_Passenger& e) {
        cout << "Could not create Passenger\n\n";
    }
    Booking* b3 = NULL;
    try {
        b3 = Booking::ReserveBooking("Delhi", "Delhi", "15/04/2021", BookingClass::AC3Tier::Type(), 
                                BookingCategory::General::Type(), p3);
    } catch(Bad_Booking& e) {
        cout << "Could not create Booking\n\n";
    }

    // Invalid date of booking
    const Passenger* p4 = NULL;
    try {
        p4 = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", 
                        Gender::Male::Type(), "100011111111", "9999888877");
    } catch(Bad_Passenger& e) {
        cout << "Could not create Passenger\n\n";
    }
    Booking* b4 = NULL;
    try {
        b4 = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2500", BookingClass::AC3Tier::Type(), 
                                BookingCategory::General::Type(), p4);
    } catch(Bad_Booking& e) {
        cout << "Could not create Booking\n\n";
    }
    
    // Same day booking
    const Passenger* p5 = NULL;
    try {
        p5 = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", 
                        Gender::Male::Type(), "100011111111", "9999888877");
    } catch(Bad_Passenger& e) {
        cout << "Could not create Passenger\n\n";
    }
    Booking* b5 = NULL;
    try {
        b5 = Booking::ReserveBooking("Delhi", "Mumbai", "09/04/2021", BookingClass::AC3Tier::Type(), 
                                BookingCategory::General::Type(), p5);
    } catch(Bad_Booking& e) {
        cout << "Could not create Booking\n\n";
    }

    // Date of booking more than one year later than date of reservation
    const Passenger* p6 = NULL;
    try {
        p6 = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", 
                        Gender::Male::Type(), "100011111111", "9999888877");
    } catch(Bad_Passenger& e) {
        cout << "Could not create Passenger\n\n";
    }
    Booking* b6 = NULL;
    try {
        b6 = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2022", BookingClass::AC3Tier::Type(), 
                                BookingCategory::General::Type(), p6);
    } catch(Bad_Booking& e) {
        cout << "Could not create Booking\n\n";
    }

    // Trying for Tatkal but date difference is more than one day
    const Passenger* p7 = NULL;
    try {
        p7 = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", 
                        Gender::Male::Type(), "100011111111", "9999888877");
    } catch(Bad_Passenger& e) {
        cout << "Could not create Passenger\n\n";
    }
    Booking* b7 = NULL;
    try {
        b7 = Booking::ReserveBooking("Delhi", "Mumbai", "30/04/2021", BookingClass::AC3Tier::Type(), 
                                BookingCategory::Tatkal::Type(), p7);
    } catch(Bad_Booking& e) {
        cout << "Could not create Booking\n\n";
    }


    // Not eligible for the Divyaang Category
    const Passenger* p8 = NULL;
    try {
        p8 = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", 
                        Gender::Male::Type(), "100011111111", "9999888877");
    } catch(Bad_Passenger& e) {
        cout << "Could not create Passenger\n\n";
    }
    Booking* b8 = NULL;
    try {
        b8 = Booking::ReserveBooking("Delhi", "Mumbai", "30/04/2021", BookingClass::AC3Tier::Type(), 
                                Divyaang::Blind::Type(), p8);
    } catch(Bad_Booking& e) {
        cout << "Could not create Booking\n\n";
    }

    // Not eligible for the Senior Citizen Category
    const Passenger* p9 = NULL;
    try {
        p9 = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/2002", 
                        Gender::Male::Type(), "100011111111", "9999888877");
    } catch(Bad_Passenger& e) {
        cout << "Could not create Passenger\n\n";
    }
    Booking* b9 = NULL;
    try {
        b9 = Booking::ReserveBooking("Delhi", "Mumbai", "30/04/2021", BookingClass::AC3Tier::Type(), 
                                BookingCategory::SeniorCitizen::Type(), p9);
    } catch(Bad_Booking& e) {
        cout << "Could not create Booking\n\n";
    }

    // Invalid Passenger Information
    const Passenger* p10 = NULL;
    try {
        p10 = Passenger::CreatePassenger("", "", "", "11/03/2002", 
                        Gender::Male::Type(), "100011111111", "9999888877");
    } catch(Bad_Passenger& e) {
        cout << "Could not create Passenger\n\n";
    }
    Booking* b10 = NULL;
    try {
        b10 = Booking::ReserveBooking("Delhi", "Mumbai", "30/04/2021", BookingClass::AC3Tier::Type(), 
                                Divyaang::SeniorCitizen::Type(), p10);
    } catch(Bad_Booking& e) {
        cout << "Could not create Booking\n\n";
    }
}
    
int main() {
    BookingApplication();

    return 0;
}