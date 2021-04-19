#ifndef FRACTION_H // guard to ensure that the header is included only once during compilation
#define FRACTION_H

#include <iostream>
#include <cmath>
using namespace std;

class Fraction
{
private :
    // We represent each fraction as p / q, where q > 0 and gcd(p, q) = 1
    int p;
    unsigned int q;

    // The precision constant used for converting double to a fraction
    static const int precsn;

    // The various static utility functions

    // Returns the precision constant used while converting a double to a fraction
    static int precision();

    // Returns the gcd of the 2 numbers passed to it
    static int gcd(int, int);

    // Returns the lcm of the 2 numbers passed to it
    static int lcm(int, int);

    // This function normalizes the fraction with which it is called, i.e., it ensures q > 0 and gcd(p, q) = 1
    void normalize();

public : 
    // The two static constants to represent 1 (= 1 / 1) and 0 (= 0 / 1) respectively
    static const Fraction sc_fUnity;
    static const Fraction sc_fZero;

    // Here we have defaulted the parameters of the constructor to make it equivalent to 3 overloaded constructors
    // This accepts Fraction(), Fraction(int) and Fraction(int, int)
    // Made explicit to not allow any implicit conversions and unexpected behaviour
    explicit Fraction(int = 1, int = 1);

    // This constructor converts a double value to a fraction using a constant precision value
    // Made explicit to not allow any implicit conversions and unexpected behaviour
    explicit Fraction(double);

    // This is the usual copy constructor where the parameter is passed by reference and is made const so that we do not change it accidentally
    Fraction(const Fraction&);

    // The usual destructor
    ~Fraction();

    // The copy assignment operator which returns a reference to the object on the LHS of the = operator (useful when the = operator is chained)
    // The object on the RHS of the = operator is made const in the parameter because we do not need to make any changes to it
    Fraction& operator=(const Fraction&);

    // These are the unary minus and plus operators, they do not change the operand, but return a new object after applying the operator
    Fraction operator-();
    Fraction operator+();

    // The prefix pre-increment and pre-decrement operators
    // They change the operand and return a reference to the same object (the operand)
    Fraction& operator--();
    Fraction& operator++();

    // The postfix post-increment and post-decrement operators
    // Here we initially copy the operand to a new object, make changes to the operand and then return the copy which we had made initially
    // So we do not return a reference here
    Fraction operator--(int);
    Fraction operator++(int);

    // The binary operators +, -, *, / and % defined using friend functions
    // We pass the arguments as const references as we do not intend to change the original operands
    // We do the appropriate operation and then return the result as a new object
    friend Fraction operator+(const Fraction&, const Fraction&);
    friend Fraction operator-(const Fraction&, const Fraction&);
    friend Fraction operator*(const Fraction&, const Fraction&);
    friend Fraction operator/(const Fraction&, const Fraction&);
    friend Fraction operator%(const Fraction&, const Fraction&);

    // These are the binary relational operators ==, !=, <, <=, > and >=
    // These are very small functions and do not have much compuatation overhead, hence they have been made inline
    // q is upcasted from unsigned int to int to avoid any overflow or underflow issues
    inline bool operator==(const Fraction &f)
    {
        return (p * (int)f.q == f.p * (int)q);
    }

    inline bool operator!=(const Fraction &f)
    {
        return (p * (int)f.q != f.p * (int)q);
    }

    inline bool operator<(const Fraction &f)
    {
        return (p * (int)f.q < f.p * (int)q);
    }

    inline bool operator<=(const Fraction &f)
    {
        return (p * (int)f.q <= f.p * (int)q);
    }

    inline bool operator>(const Fraction &f)
    {
        return (p * (int)f.q > f.p * (int)q);
    }

    inline bool operator>=(const Fraction &f)
    {
        return (p * (int)f.q >= f.p * (int)q);
    }

    // The special operator ! which returns the inverse of the fraction object with which it has been called, provided it is not 0
    Fraction operator!();

    // The streaming I/O operators
    // For ostream, the object as a parameter is made const because we do not need to change it while displaying it
    // It returns the same ostream object as a reference which helps when the operator is chained
    friend ostream& operator<<(ostream&, const Fraction&);

    // For istream, the object as a parameter is not made const, because we are accepting its values from the user, andf hence we need to change its contents
    // It returns the same istream object as a reference which helps when the operator is chained
    friend istream& operator>>(istream&, Fraction&);
};

#endif // FRACTION_H