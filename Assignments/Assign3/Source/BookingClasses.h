/*
    CS20006 Assignment 3
    BookingClasses.h
    @author Ashutosh Kumar Singh (19CS30008)
*/

// Header File for the hierarchy of booking classes

#ifndef __BOOKINGCLASSES_H // Control inclusion of header files
#define __BOOKINGCLASSES_H

// C++ Headers
#include <iostream>
using namespace std;

// Abstract Base Class
class BookingClasses
{
protected:
    // Data members to be present in each concrete child class
    const string name_;
    const bool isAC_;
    const bool isLuxury_;

    BookingClasses(const string&, const bool, const bool); // Constructor
    virtual ~BookingClasses(); // Virtual Destructor

public:
    virtual double GetLoadFactor() const = 0;
    string GetName() const;
    virtual bool IsSitting() const = 0;
    bool IsAC() const;
    virtual int GetNumberOfTiers() const = 0;
    bool IsLuxury() const;

    friend ostream& operator<<(ostream&, const BookingClasses&); // Output streaming operator
};

// Berth - inherits from BookingClasses and serves as an abstract parent class for all booking classes having sleeping berths
class Berth: public BookingClasses
{  
protected:
    Berth(const string&, const bool, const bool); // Constructor
    ~Berth();

public:
    virtual bool IsSitting() const; // Defining the IsSitting() function which was pure virtual in the base class
};

// Seat - inherits from BookingClasses and serves as an abstract parent class for all booking classes having seats
class Seat: public BookingClasses
{
protected:
    Seat(const string&, const bool, const bool); // Constructor
    ~Seat();

public:
    virtual bool IsSitting() const; // Defining the IsSitting() function which was pure virtual in the base class
    virtual int GetNumberOfTiers() const; // Defining the GetNumberOfTiers() function which was pure virtual in the base class
};

// Tiers2 - inherits from Berth and serves as an abstract parent class for all booking classes with 2 tiers
class Tiers2: public Berth
{
protected:
    Tiers2(const string&, const bool, const bool); // Constructor
    ~Tiers2();

public:
    virtual int GetNumberOfTiers() const; // Defining the GetNumberOfTiers() function which was pure virtual in the base class
};

// Tiers3 - inherits from Berth and serves as an abstract parent class for all booking classes with 3 tiers
class Tiers3: public Berth
{
protected:
    Tiers3(const string&, const bool, const bool); // Constructor
    ~Tiers3();
    
public:
    virtual int GetNumberOfTiers() const; // Defining the GetNumberOfTiers() function which was pure virtual in the base class
};

// Concrete Class Declarations
// Class declaration for ACFirstClass
class ACFirstClass: public Tiers2
{
private:
    ACFirstClass();
    ~ACFirstClass();

    ACFirstClass(const ACFirstClass&);
    ACFirstClass& operator=(const ACFirstClass&);

public:
    static const double sLoadFactor;
    static const ACFirstClass& Type();
    virtual double GetLoadFactor() const;
    static void UnitTestACFirstClass();
};

// Class declaration for AC2Tier
class AC2Tier: public Tiers2
{
private:
    AC2Tier();
    ~AC2Tier();

    AC2Tier(const AC2Tier&);
    AC2Tier& operator=(const AC2Tier&);

public:
    static const double sLoadFactor;
    static const AC2Tier& Type();
    virtual double GetLoadFactor() const;
    static void UnitTestAC2Tier();
};

// Class declaration for FirstClass
class FirstClass: public Tiers2
{
private:
    FirstClass();
    ~FirstClass();

    FirstClass(const FirstClass&);
    FirstClass& operator=(const FirstClass&);

public:
    static const double sLoadFactor;
    static const FirstClass& Type();
    virtual double GetLoadFactor() const;
    static void UnitTestFirstClass();
};

// Class declaration for AC3Tier
class AC3Tier: public Tiers3
{
private:
    AC3Tier();
    ~AC3Tier();

    AC3Tier(const AC3Tier&);
    AC3Tier& operator=(const AC3Tier&);

public:
    static const double sLoadFactor;
    static const AC3Tier& Type();
    virtual double GetLoadFactor() const;
    static void UnitTestAC3Tier();
};

// Class declaration for ACChairCar
class ACChairCar: public Seat
{
private:
    ACChairCar();
    ~ACChairCar();

    ACChairCar(const ACChairCar&);
    ACChairCar& operator=(const ACChairCar&);

public:
    static const double sLoadFactor;
    static const ACChairCar& Type();
    virtual double GetLoadFactor() const;
    static void UnitTestACChairCar();
};

// Class declaration for Sleeper
class Sleeper: public Tiers3
{
private:
    Sleeper();
    ~Sleeper();

    Sleeper(const Sleeper&);
    Sleeper& operator=(const Sleeper&);

public:
    static const double sLoadFactor;
    static const Sleeper& Type();
    virtual double GetLoadFactor() const;
    static void UnitTestSleeper();
};

// Class declaration for SecondSitting
class SecondSitting: public Seat
{
private:
    SecondSitting();
    ~SecondSitting();

    SecondSitting(const SecondSitting&);
    SecondSitting& operator=(const SecondSitting&);

public:
    static const double sLoadFactor;
    static const SecondSitting& Type();
    virtual double GetLoadFactor() const;
    static void UnitTestSecondSitting();
};

#endif // __BOOKINGCLASSES_H