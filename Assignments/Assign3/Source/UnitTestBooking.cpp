/*
    CS20006 Assignment 3
    UnitTestBooking.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

/*
    COMPILATION AND BUILD COMMANDS :
    g++ -std=c++11 Station.cpp Railways.cpp Date.cpp BookingClasses.cpp Booking.cpp UnitTestBooking.cpp -o test
    ./test
*/

// Unit Testing File for class Booking

// Including project header files
#include "Booking.h"

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

const double Booking::sBaseFarePerKM = 0.5;
const int Booking::sACSurcharge = 50;
const int Booking::sLuxuryTaxPercent = 25;

void Booking::UnitTestBooking()
{
    // Testing the constructor
    // Pass all arguments except bookingStatus_, bookingMessage_ and passenger
    Booking b1(Station("Kolkata"), Station("Delhi"), Date(11, 3, 2021), ACFirstClass::Type());

    // Check the values of attributes of the created object
    assert("Kolkata" == b1.fromStation_.GetName() && "Delhi" == b1.toStation_.GetName() && "AC First Class" == b1.bookingClass_.GetName()
            && true == b1.bookingStatus_ && "BOOKING SUCCEEDED" == b1.bookingMessage_ && NULL == b1.passenger_ && 1 == b1.PNR_);

    // Pass all arguments except bookingMessage_ and passenger
    Booking b2(Station("Kolkata"), Station("Delhi"), Date(11, 3, 2021), ACFirstClass::Type(), true);

    // Check the values of attributes of the created object
    assert("Kolkata" == b2.fromStation_.GetName() && "Delhi" == b2.toStation_.GetName() && "AC First Class" == b2.bookingClass_.GetName()
            && true == b2.bookingStatus_ && "BOOKING SUCCEEDED" == b2.bookingMessage_ && NULL == b2.passenger_ && 2 == b2.PNR_);

    // Pass all arguments except passenger
    Booking b3(Station("Kolkata"), Station("Delhi"), Date(11, 3, 2021), ACFirstClass::Type(), true, "BOOKING SUCCEEDED");

    // Check the values of attributes of the created object
    assert("Kolkata" == b3.fromStation_.GetName() && "Delhi" == b3.toStation_.GetName() && "AC First Class" == b3.bookingClass_.GetName()
            && true == b3.bookingStatus_ && "BOOKING SUCCEEDED" == b3.bookingMessage_ && NULL == b3.passenger_ && 3 == b3.PNR_);

    // Testing the ComputeFare() function
    // For a booking with ACFirstClass
    Booking b4(Station("Kolkata"), Station("Delhi"), Date(11, 3, 2021), ACFirstClass::Type());
    assert(2823 == b4.fare_);

    // For a booking with AC2Tier
    Booking b5(Station("Kolkata"), Station("Delhi"), Date(11, 3, 2021), AC2Tier::Type());
    assert(1522 == b5.fare_);

    // For a booking with FirstClass
    Booking b6(Station("Kolkata"), Station("Delhi"), Date(11, 3, 2021), FirstClass::Type());
    assert(1840 == b6.fare_);

    // For a booking with AC3Tier
    Booking b7(Station("Kolkata"), Station("Delhi"), Date(11, 3, 2021), AC3Tier::Type());
    assert(1338 == b7.fare_);

    // For a booking with ACChairCar
    Booking b8(Station("Kolkata"), Station("Delhi"), Date(11, 3, 2021), ACChairCar::Type());
    assert(970 == b8.fare_);

    // For a booking with Sleeper
    Booking b9(Station("Kolkata"), Station("Delhi"), Date(11, 3, 2021), Sleeper::Type());
    assert(736 == b9.fare_);

    // For a booking with SecondSitting
    Booking b10(Station("Kolkata"), Station("Delhi"), Date(11, 3, 2021), SecondSitting::Type());
    assert(368 == b10.fare_);

    // Testing the ostream operator
    stringstream out;
    out << b1;
    
    string expectedOutput = "BOOKING SUCCEEDED\nPNR Number = 1\nFrom Station = Kolkata\nTo Station = Delhi\nTravel Date = Thu, 11/Mar/2021\nTravel Class = AC First Class\n"
                            "  : Mode: Sleeping\n  : Comfort: AC\n  : Bunks: 2\n  : Luxury: Yes\nFare = 2823\n";
    assert(expectedOutput == out.str()); // Match the output with the expected output

    // Also print the object to the screen for better clarity
    cout << b1 << endl;

    // If the control has reached here, it means that all unit tests have passed
    cout << "*** ALL UNIT TESTS FOR CLASS Booking PASSED ***\n";
}

int main()
{
    Booking::UnitTestBooking();

    return 0;
}