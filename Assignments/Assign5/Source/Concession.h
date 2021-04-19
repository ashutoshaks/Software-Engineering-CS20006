/*
    CS20006 Assignment 5
    Concession.h
    @author Ashutosh Kumar Singh (19CS30008)
*/

#ifndef __CONCESSION_H
#define __CONCESSION_H

#include "Passenger.h"

#include <iostream>
#include <string>
#include <map>
using namespace std;

class BookingClass;
class Divyaang;

class Concession {
protected:
    string name_;

    Concession(const string&);
    ~Concession() {}
};

class GeneralConcession : public Concession {
private:
    static const double sFactor;
    GeneralConcession();
    ~GeneralConcession() {}

public:
    static const GeneralConcession& Type();
    const double GetFactor() const;

    static void UnitTestGeneralConcession();
};

class LadiesConcession : public Concession {
private:
    static const double sFactor;
    LadiesConcession();
    ~LadiesConcession() {}

public:
    static const LadiesConcession& Type();
    const double GetFactor() const;

    static void UnitTestLadiesConcession();
};

class SeniorCitizenConcession : public Concession {
private:
    static const double sFactorMale;
    static const double sFactorFemale;

    SeniorCitizenConcession();
    ~SeniorCitizenConcession() {}

public:
    static const SeniorCitizenConcession& Type();
    const double GetFactor(const Passenger&) const;

    static void UnitTestSeniorCitizenConcession();
};

class DivyaangConcession : public Concession {
private:
    static const map<pair<const BookingClass*, const Divyaang*>, double> sFactor;
    DivyaangConcession();
    ~DivyaangConcession() {}

public:
    static const DivyaangConcession& Type();
    const double GetFactor(const Passenger&, const BookingClass&) const;

    static void UnitTestDivyaangConcession();
};

#endif // CONCESSION_H