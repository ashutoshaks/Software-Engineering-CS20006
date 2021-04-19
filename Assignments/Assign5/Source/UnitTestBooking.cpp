/*
    CS20006 Assignment 5
    UnitTestBooking.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

/*
    COMPILATION AND BUILD COMMANDS :
    g++ -std=c++11 Station.cpp Railways.cpp Date.cpp Gender.cpp Name.cpp Passenger.cpp BookingClass.cpp BookingCategory.cpp Concession.cpp Booking.cpp Exceptions.cpp UnitTestBooking.cpp -o test
    ./test
*/

// Unit Testing File for class Booking

// Including project header files
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


const double Booking::sBaseFarePerKM = 0.5;

void Booking::UnitTestBooking() {
    
    const Passenger* pgeneral = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/1975", Gender::Male::Type(), "123456789012");
    const Passenger* pladies = Passenger::CreatePassenger("Arya", "Kumari", "Singh", "11/03/1978", Gender::Female::Type(), "123456789012");
    const Passenger* pseniorm = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/1950", Gender::Male::Type(), "123456789012");
    const Passenger* pseniorf = Passenger::CreatePassenger("Arya", "Kumari", "Singh", "11/03/1961", Gender::Female::Type(), "123456789012");
    const Passenger* pblind = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/1950", Gender::Male::Type(), "123456789012", "9999888877", &Divyaang::Blind::Type(), "012");
    const Passenger* portho = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/1950", Gender::Male::Type(), "123456789012", "9999888877", &Divyaang::OrthoHandicapped::Type(), "012");
    const Passenger* pcancer = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/1950", Gender::Female::Type(), "123456789012", "9999888877", &Divyaang::Cancer::Type(), "012");
    const Passenger* ptb = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/1950", Gender::Female::Type(), "123456789012", "9999888877", &Divyaang::TB::Type(), "012");

    // Check for all pairs of stations and all booking categories

    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::AC3Tier::Type(), BookingCategory::General::Type(), pgeneral);
        cout << b -> fare_ << endl;
        assert(1849 == b -> fare_);
    } catch (Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Kolkata", "Delhi", "15/04/2021", BookingClass::AC3Tier::Type(), BookingCategory::Ladies::Type(), pladies);
        cout << b -> fare_ << endl;
        assert(1880 == b -> fare_);
    } catch (Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Chennai", "15/04/2021", BookingClass::AC3Tier::Type(), BookingCategory::SeniorCitizen::Type(), pseniorm);
        cout << b -> fare_ << endl;
        assert(1675 == b -> fare_);
    } catch (Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Bangalore", "15/04/2021", BookingClass::AC3Tier::Type(), BookingCategory::SeniorCitizen::Type(), pseniorf);
        cout << b -> fare_ << endl;
        assert(1384 == b -> fare_);
    } catch (Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Bangalore", "Mumbai", "10/04/2021", BookingClass::AC3Tier::Type(), BookingCategory::Tatkal::Type(), pgeneral);
        cout << b -> fare_ << endl;
        assert(1634 == b -> fare_);
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Chennai", "Bangalore", "10/04/2021", BookingClass::AC3Tier::Type(), BookingCategory::PremiumTatkal::Type(), pladies);
        cout << b -> fare_ << endl;
        assert(478 == b -> fare_);
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Bangalore", "Kolkata", "15/04/2021", BookingClass::AC3Tier::Type(), Divyaang::Blind::Type() , pblind);
        cout << b -> fare_ << endl;
        assert(625 == b -> fare_);
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Kolkata", "Mumbai", "15/04/2021", BookingClass::AC3Tier::Type(), Divyaang::Cancer::Type(), pcancer);
        cout << b -> fare_ << endl;
        assert(40 == b -> fare_);
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Mumbai", "Chennai", "15/04/2021", BookingClass::AC3Tier::Type(), Divyaang::OrthoHandicapped::Type(), portho);
        cout << b -> fare_ << endl;
        assert(458 == b -> fare_);
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Chennai", "Kolkata", "15/04/2021", BookingClass::AC3Tier::Type(), Divyaang::TB::Type(), ptb);
        cout << b -> fare_ << endl;
        assert(2114 == b -> fare_);
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    // Now, vary the booking class

    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::ACFirstClass::Type(), BookingCategory::General::Type(), pgeneral);
        cout << b -> fare_ << endl;
        assert(4763 == b -> fare_);
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::AC2Tier::Type(), BookingCategory::General::Type(), pgeneral);
        cout << b -> fare_ << endl;
        assert(2944 == b -> fare_);
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::AC3Tier::Type(), BookingCategory::General::Type(), pgeneral);
        cout << b -> fare_ << endl;
        assert(1849 == b -> fare_);
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::ACChairCar::Type(), BookingCategory::General::Type(), pgeneral);
        cout << b -> fare_ << endl;
        assert(1487 == b -> fare_);
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::FirstClass::Type(), BookingCategory::General::Type(), pgeneral);
        cout << b -> fare_ << endl;
        assert(2221 == b -> fare_);
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::Sleeper::Type(), BookingCategory::General::Type(), pgeneral);
        cout << b -> fare_ << endl;
        assert(744 == b -> fare_);
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::SecondSitting::Type(), BookingCategory::General::Type(), pgeneral);
        cout << b -> fare_ << endl;
        assert(449 == b -> fare_);
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::ExecutiveChairCar::Type(), BookingCategory::General::Type(), pgeneral);
        cout << b -> fare_ << endl;
        assert(3678 == b -> fare_);
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }
    
}

int main() {
    Booking::UnitTestBooking();

    return 0;
}