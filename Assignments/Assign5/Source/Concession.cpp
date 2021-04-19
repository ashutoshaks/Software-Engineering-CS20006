/*
    CS20006 Assignment 5
    Concession.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

#include "Concession.h"
#include "BookingClass.h"
#include "BookingCategory.h"

// initialize static constants

const double GeneralConcession::sFactor = 0.00;
const double LadiesConcession::sFactor = 0.00;
const double  SeniorCitizenConcession::sFactorMale = 0.40;
const double  SeniorCitizenConcession::sFactorFemale = 0.50;

const map<pair<const BookingClass*, const Divyaang*>, double> DivyaangConcession::sFactor = 
{
{{&BookingClass::ACFirstClass::Type(), &Divyaang::Blind::Type()}, 0.50},
{{&BookingClass::ACFirstClass::Type(), &Divyaang::OrthoHandicapped::Type()}, 0.50},
{{&BookingClass::ACFirstClass::Type(), &Divyaang::Cancer::Type()}, 0.50},
{{&BookingClass::ACFirstClass::Type(), &Divyaang::TB::Type()}, 0.00},

{{&BookingClass::ExecutiveChairCar::Type(), &Divyaang::Blind::Type()}, 0.75},
{{&BookingClass::ExecutiveChairCar::Type(), &Divyaang::OrthoHandicapped::Type()}, 0.75},
{{&BookingClass::ExecutiveChairCar::Type(), &Divyaang::Cancer::Type()}, 0.75},
{{&BookingClass::ExecutiveChairCar::Type(), &Divyaang::TB::Type()}, 0.00},

{{&BookingClass::AC2Tier::Type(), &Divyaang::Blind::Type()}, 0.50},
{{&BookingClass::AC2Tier::Type(), &Divyaang::OrthoHandicapped::Type()}, 0.50},
{{&BookingClass::AC2Tier::Type(), &Divyaang::Cancer::Type()}, 0.50},
{{&BookingClass::AC2Tier::Type(), &Divyaang::TB::Type()}, 0.00},

{{&BookingClass::FirstClass::Type(), &Divyaang::Blind::Type()}, 0.75},
{{&BookingClass::FirstClass::Type(), &Divyaang::OrthoHandicapped::Type()}, 0.75},
{{&BookingClass::FirstClass::Type(), &Divyaang::Cancer::Type()}, 0.75},
{{&BookingClass::FirstClass::Type(), &Divyaang::TB::Type()}, 0.75},

{{&BookingClass::AC3Tier::Type(), &Divyaang::Blind::Type()}, 0.75},
{{&BookingClass::AC3Tier::Type(), &Divyaang::OrthoHandicapped::Type()}, 0.75},
{{&BookingClass::AC3Tier::Type(), &Divyaang::Cancer::Type()}, 1.00},
{{&BookingClass::AC3Tier::Type(), &Divyaang::TB::Type()}, 0.00},

{{&BookingClass::ACChairCar::Type(), &Divyaang::Blind::Type()}, 0.75},
{{&BookingClass::ACChairCar::Type(), &Divyaang::OrthoHandicapped::Type()}, 0.75},
{{&BookingClass::ACChairCar::Type(), &Divyaang::Cancer::Type()}, 1.00},
{{&BookingClass::ACChairCar::Type(), &Divyaang::TB::Type()}, 0.00},

{{&BookingClass::Sleeper::Type(), &Divyaang::Blind::Type()}, 0.75},
{{&BookingClass::Sleeper::Type(), &Divyaang::OrthoHandicapped::Type()}, 0.75},
{{&BookingClass::Sleeper::Type(), &Divyaang::Cancer::Type()}, 1.00},
{{&BookingClass::Sleeper::Type(), &Divyaang::TB::Type()}, 0.75},

{{&BookingClass::SecondSitting::Type(), &Divyaang::Blind::Type()}, 0.75},
{{&BookingClass::SecondSitting::Type(), &Divyaang::OrthoHandicapped::Type()}, 0.75},
{{&BookingClass::SecondSitting::Type(), &Divyaang::Cancer::Type()}, 1.00},
{{&BookingClass::SecondSitting::Type(), &Divyaang::TB::Type()}, 0.75}
};


Concession::Concession(const string& name) : name_(name) {}

GeneralConcession::GeneralConcession() : Concession("General Concession") {}

const GeneralConcession& GeneralConcession::Type() {
    static const GeneralConcession theObject;
    return theObject;
}

const double GeneralConcession::GetFactor() const {
    return GeneralConcession::sFactor;
}

LadiesConcession::LadiesConcession() : Concession("Ladies Concession") {}

const LadiesConcession& LadiesConcession::Type() {
    static const LadiesConcession theObject;
    return theObject;
}

const double LadiesConcession::GetFactor() const {
    return LadiesConcession::sFactor;
}

SeniorCitizenConcession::SeniorCitizenConcession() : Concession("Senior Citizen Concession") {}

const SeniorCitizenConcession& SeniorCitizenConcession::Type() {
    static const SeniorCitizenConcession theObject;
    return theObject;
}

const double SeniorCitizenConcession::GetFactor(const Passenger& passenger) const {
    if(Gender::IsMale(passenger.GetGender()))
        return SeniorCitizenConcession::sFactorMale;
    else
        return SeniorCitizenConcession::sFactorFemale;
}

DivyaangConcession::DivyaangConcession() : Concession("Divyaang Concession") {}

const DivyaangConcession& DivyaangConcession::Type() {
    static const DivyaangConcession theObject;
    return theObject;
}

const double DivyaangConcession::GetFactor(const Passenger& passenger, const BookingClass& bookingClass) const {
    return DivyaangConcession::sFactor.at({&bookingClass, passenger.GetDisability()});
}