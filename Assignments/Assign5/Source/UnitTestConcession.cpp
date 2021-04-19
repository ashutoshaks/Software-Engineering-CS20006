/*
    CS20006 Assignment 5
    UnitTestConcession.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

/*
    COMPILATION AND BUILD COMMANDS :
    g++ -std=c++11 Concession.cpp Date.cpp Passenger.cpp BookingClass.cpp BookingCategory.cpp Gender.cpp Name.cpp Booking.cpp Station.cpp Railways.cpp Exceptions.cpp UnitTestConcession.cpp -o test
    ./test
*/

// Unit Testing File for the Concession class

// Including project header files
#include "Concession.h"
#include "Exceptions.h"
#include "BookingClass.h"
#include "BookingCategory.h"
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

void GeneralConcession::UnitTestGeneralConcession() {
    const GeneralConcession* firstPointer = &GeneralConcession::Type();
    const GeneralConcession* secondPointer = &GeneralConcession::Type();
    assert(firstPointer == secondPointer);

    double fac = GeneralConcession::Type().GetFactor();
    assert(0.00 == fac);
}

void LadiesConcession::UnitTestLadiesConcession() {
    const LadiesConcession* firstPointer = &LadiesConcession::Type();
    const LadiesConcession* secondPointer = &LadiesConcession::Type();
    assert(firstPointer == secondPointer);

    double fac = LadiesConcession::Type().GetFactor();
    assert(0.00 == fac);
}

void SeniorCitizenConcession::UnitTestSeniorCitizenConcession() {
    const SeniorCitizenConcession* firstPointer = &SeniorCitizenConcession::Type();
    const SeniorCitizenConcession* secondPointer = &SeniorCitizenConcession::Type();
    assert(firstPointer == secondPointer);

    const Passenger* p1 = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/1950", Gender::Male::Type(), "123456789012");
    double fac = SeniorCitizenConcession::Type().GetFactor(*p1);
    assert(0.40 == fac);

    const Passenger* p2 = Passenger::CreatePassenger("Arya", "Kumari", "Singh", "11/03/1950", Gender::Female::Type(), "123456789012");
    fac = SeniorCitizenConcession::Type().GetFactor(*p2);
    assert(0.50 == fac);
}

void DivyaangConcession::UnitTestDivyaangConcession() {
    const DivyaangConcession* firstPointer = &DivyaangConcession::Type();
    const DivyaangConcession* secondPointer = &DivyaangConcession::Type();
    assert(firstPointer == secondPointer);

    const Passenger* pblind = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/1950", Gender::Male::Type(), "123456789012", "9999999999", &Divyaang::Blind::Type(), "012");
    const Passenger* portho = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/1950", Gender::Male::Type(), "123456789012", "9999999999", &Divyaang::OrthoHandicapped::Type(), "012");
    const Passenger* pcancer = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/1950", Gender::Female::Type(), "123456789012", "9999999999", &Divyaang::Cancer::Type(), "012");
    const Passenger* ptb = Passenger::CreatePassenger("Ashutosh", "Kumar", "Singh", "11/03/1950", Gender::Female::Type(), "123456789012", "9999999999", &Divyaang::TB::Type(), "012");

    double fac = DivyaangConcession::Type().GetFactor(*pblind, BookingClass::ACFirstClass::Type());
    assert(0.50 == fac);
    fac = DivyaangConcession::Type().GetFactor(*pblind, BookingClass::ExecutiveChairCar::Type());
    assert(0.75 == fac);
    fac = DivyaangConcession::Type().GetFactor(*pblind, BookingClass::AC2Tier::Type());
    assert(0.50 == fac);
    fac = DivyaangConcession::Type().GetFactor(*pblind, BookingClass::FirstClass::Type());
    assert(0.75 == fac);
    fac = DivyaangConcession::Type().GetFactor(*pblind, BookingClass::AC3Tier::Type());
    assert(0.75 == fac);
    fac = DivyaangConcession::Type().GetFactor(*pblind, BookingClass::ACChairCar::Type());
    assert(0.75 == fac);
    fac = DivyaangConcession::Type().GetFactor(*pblind, BookingClass::Sleeper::Type());
    assert(0.75 == fac);
    fac = DivyaangConcession::Type().GetFactor(*pblind, BookingClass::SecondSitting::Type());
    assert(0.75 == fac);
    
    fac = DivyaangConcession::Type().GetFactor(*portho, BookingClass::ACFirstClass::Type());
    assert(0.50 == fac);
    fac = DivyaangConcession::Type().GetFactor(*portho, BookingClass::ExecutiveChairCar::Type());
    assert(0.75 == fac);
    fac = DivyaangConcession::Type().GetFactor(*portho, BookingClass::AC2Tier::Type());
    assert(0.50 == fac);
    fac = DivyaangConcession::Type().GetFactor(*portho, BookingClass::FirstClass::Type());
    assert(0.75 == fac);
    fac = DivyaangConcession::Type().GetFactor(*portho, BookingClass::AC3Tier::Type());
    assert(0.75 == fac);
    fac = DivyaangConcession::Type().GetFactor(*portho, BookingClass::ACChairCar::Type());
    assert(0.75 == fac);
    fac = DivyaangConcession::Type().GetFactor(*portho, BookingClass::Sleeper::Type());
    assert(0.75 == fac);
    fac = DivyaangConcession::Type().GetFactor(*portho, BookingClass::SecondSitting::Type());
    assert(0.75 == fac);
    
    fac = DivyaangConcession::Type().GetFactor(*pcancer, BookingClass::ACFirstClass::Type());
    assert(0.50 == fac);
    fac = DivyaangConcession::Type().GetFactor(*pcancer, BookingClass::ExecutiveChairCar::Type());
    assert(0.75 == fac);
    fac = DivyaangConcession::Type().GetFactor(*pcancer, BookingClass::AC2Tier::Type());
    assert(0.50 == fac);
    fac = DivyaangConcession::Type().GetFactor(*pcancer, BookingClass::FirstClass::Type());
    assert(0.75 == fac);
    fac = DivyaangConcession::Type().GetFactor(*pcancer, BookingClass::AC3Tier::Type());
    assert(1.00 == fac);
    fac = DivyaangConcession::Type().GetFactor(*pcancer, BookingClass::ACChairCar::Type());
    assert(1.00 == fac);
    fac = DivyaangConcession::Type().GetFactor(*pcancer, BookingClass::Sleeper::Type());
    assert(1.00 == fac);
    fac = DivyaangConcession::Type().GetFactor(*pcancer, BookingClass::SecondSitting::Type());
    assert(1.00 == fac);

    fac = DivyaangConcession::Type().GetFactor(*ptb, BookingClass::ACFirstClass::Type());
    assert(0.00 == fac);
    fac = DivyaangConcession::Type().GetFactor(*ptb, BookingClass::ExecutiveChairCar::Type());
    assert(0.00 == fac);
    fac = DivyaangConcession::Type().GetFactor(*ptb, BookingClass::AC2Tier::Type());
    assert(0.00 == fac);
    fac = DivyaangConcession::Type().GetFactor(*ptb, BookingClass::FirstClass::Type());
    assert(0.75 == fac);
    fac = DivyaangConcession::Type().GetFactor(*ptb, BookingClass::AC3Tier::Type());
    assert(0.00 == fac);
    fac = DivyaangConcession::Type().GetFactor(*ptb, BookingClass::ACChairCar::Type());
    assert(0.00 == fac);
    fac = DivyaangConcession::Type().GetFactor(*ptb, BookingClass::Sleeper::Type());
    assert(0.75 == fac);
    fac = DivyaangConcession::Type().GetFactor(*ptb, BookingClass::SecondSitting::Type());
    assert(0.75 == fac);
}

int main() {
    GeneralConcession::UnitTestGeneralConcession();
    LadiesConcession::UnitTestLadiesConcession();
    SeniorCitizenConcession::UnitTestSeniorCitizenConcession();
    DivyaangConcession::UnitTestDivyaangConcession();
    return 0;
}
