#include "Fraction.hxx"

// Declaration of all the static constants
const Fraction Fraction::sc_fUnity = Fraction(); // 1 / 1
const Fraction Fraction::sc_fZero = Fraction(0); // 0 / 1
const int Fraction::precsn = (int)1e5;

// Returns the precision value used for converting a double to fraction
int Fraction::precision()
{
    return Fraction::precsn;
}

// This function computes the gcd of a and b using the standard Eucledian algorithm
int Fraction::gcd(int a, int b)
{
    return ((a == 0) ? b : gcd(b % a, a)); 
}

// This function returns the lcm of a and b
int Fraction::lcm(int a, int b)
{
    return ((a * b) / gcd(a, b));
}

void Fraction::normalize()
{   
    // if the fraction is 0, return it as 0 / 1
    if(p == 0)
    {
        q = 1;
        return;
    }
    // It is already always ensured that q > 0
    // This ensures that at the end gcd(p, q) = 1
    int hcf = gcd(abs(p), q);
    p /= hcf;
    q /= hcf;
}

// Constructor with both parameters defaulted (in header file)
Fraction::Fraction(int m, int n)
{   
    // If the denominator is 0, exit with error code 1
    if(n == 0)
        exit(1);
    else if(n < 0)
    {
        m *= -1;
        n *= -1;
    }
    p = m;
    q = n;
    this -> normalize();   
}

// Constructor for converting a double value to a fraction
Fraction::Fraction(double d)
{   
    int sign = (d < 0 ? -1 : 1);
    d = abs(d);
    int dnum = (int)floor(d);
    double num = d - floor(d);
    Fraction frac((num * precsn), precsn);
    Fraction dec(dnum, 1);
    Fraction res = dec + frac;
    p = res.p * sign;
    q = res.q;
    this -> normalize();
}

// Copy constructor
Fraction::Fraction(const Fraction &f) : p(f.p), q(f.q)
{
    this -> normalize();
}

// Note that we have called normalize() in every constructor to ensure that the fraction stays in the specified format

// Destructor
Fraction::~Fraction()
{}

// Copy assignment operator
Fraction& Fraction::operator=(const Fraction &f)
{
    // Check for self-copy, if that is the case, do nothing
    if(this != &f)
    {
        p = f.p;
        q = f.q;
    }
    return *this; // Return the object on the LHS of the = operator as reference
}

// Unary arithmetic operators
// Unary minus
Fraction Fraction::operator-()
{
    // Creating a new object with p changed to -p and returning this new object
    Fraction res(-p, q);
    return res;
}

// Unary plus
Fraction Fraction::operator+()
{
    // Creating a new object with the same value as the previous object and returning it
    Fraction res(p, q);
    return res;
}

// Pre-decrement
// In these operators there is no need to normalize, because if gcd(p, q) = 1, that implies gcd(p + q, q) = 1 and gcd(p - q, q) = 1
Fraction& Fraction::operator--()
{
    // Changes (p / q) to (p / q) - 1 = (p - q) / q and returns the same object by reference
    p = p - q;
    return *this;
}

// Pre-increment
Fraction& Fraction::operator++()
{
    // Changes (p / q) to (p / q) + 1 = (p + q) / q and returns the same object by reference
    p = p + q;
    return *this;
}

// Post-decrement
Fraction Fraction::operator--(int)
{
    Fraction res(p, q); // Copies the original fraction object to a new object 
    p = p - q; // Changes the original object
    return res; // Returns the newly created object
}

// Post-increment
Fraction Fraction::operator++(int)
{
    Fraction res(p, q); // Copies the original fraction object to a new object 
    p = p + q; // Changes the original object
    return res; // Returns the newly created object
}

// Binary arithmetic operators
// Binary addition operator
Fraction operator+(const Fraction &f1, const Fraction &f2)
{
    Fraction res;
    res.q = Fraction::lcm(f1.q, f2.q); // The denominator of the sum will be the lcm of the 2 denominators
    res.p = f1.p * (int)(res.q / f1.q) + f2.p * (int)(res.q / f2.q); // Find the numerator appropriately
    res.normalize();
    return res;
}

// Binary subtraction operator
Fraction operator-(const Fraction &f1, const Fraction &f2)
{
    Fraction res;
    res.q = Fraction::lcm(f1.q, f2.q); // The denominator of the difference will be the lcm of the 2 denominators
    res.p = f1.p * (int)(res.q / f1.q) - f2.p * (int)(res.q / f2.q); // Find the numerator appropriately
    res.normalize();
    return res;
}

// Binary multiplication operator
Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    Fraction res;
    res.p = f1.p * f2.p; // Multiply both numerators to get the numerator of the product
    res.q = f1.q * f2.q; // Multiply both denominators to get the denominator of the product
    res.normalize();
    return res;
}

// Binary division operator
Fraction operator/(const Fraction &f1, const Fraction &f2)
{
    // If the fraction f2 is 0, we display an error message and exit with error code 1
    if(f2.p == 0)
    {
        cout << "Trying to divide by 0\n";
        exit(1);
    }
    Fraction res;
    res.p = f1.p * (int)f2.q; // Multiply numerator of f1 with denominator of f2 to get the numerator after division
    res.q = (int)f1.q * f2.p; // Multiply denominator of f1 with numerator of f2 to get the denominator after division
    res.normalize();
    return res;
}

// Binary remainder(modulo) operator
// Suppose we want the remainder when f1 is divided by f2
// We keep on subtracting f2 from f1 until f1 becomes less than f2
// So to implement this, we can divide f1 by f2 and take the integral part of the quotient
// This will be the number of times we will be able to subtract f2 from f1 before f1 becomes less than f2, let us call it x
// So the remainder can be written as f1 - (x * f2)
Fraction operator%(const Fraction &f1, const Fraction &f2)
{
    // If the fraction f2 is 0, we display an error message and exit with error code 1
    if(f2.p == 0)
    {
        cout << "Trying to divide by 0\n";
        exit(1);
    }
    Fraction div = f1 / f2; // Find the result after dividing both fractions
    Fraction quotient((int)(div.p / (int)div.q)); // Find the integral part of the quotient and store it as a Fraction object
    Fraction res = f1 - (quotient * f2);
    return res;
}

// Special operator !
Fraction Fraction::operator!()
{
    // If the fraction is 0, we display an error message and exit with error code 1
    if(p == 0)
    {
        cout << "Trying to find inverse of 0\n";
        exit(1);
    }
    Fraction res(q, p); // Create a new fraction with roles of p and q reversed
    return res;
}

// I/O operators
// Streaming to ostream
ostream& operator<<(ostream &os, const Fraction &f)
{
    // We do not display the divider if the fraction is actually a whole number
    if(f.q == 1)
        os << f.p;
    else
        os << f.p << " / " << f.q; // Display the numerator and denominator separated by / 
    return os;
}

// Streaming from istream
istream& operator>>(istream &is, Fraction &f)
{
    int m, n;
    is >> m >> n;
    Fraction temp(m, n); // use a dummy fraction to normalize, because q is unsigned int and if the entered no. is negative, that will cause errors
    // assign the normalized values to f
    f.p = temp.p;
    f.q = temp.q;
    return is;
}
