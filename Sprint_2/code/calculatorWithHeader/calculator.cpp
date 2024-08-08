#include "calculator.h"
#include <cmath>

Calculator::Calculator() {}

double Calculator::add(double a, double b)
{
    return a + b;
}
double Calculator::subtract(double a, double b)
{
    return a - b;
}
double Calculator::multiply(double a, double b)
{
    return a * b;
}
double Calculator::divide(double a, double b)
{
    if (b != 0)
    {
        return a / b;
    }
    else
    {

        return NAN;
    }
}
double Calculator::square(double a)
{
    return a * a;
}
double Calculator::cube(double a)
{
    return a * a * a;
}
double Calculator::power(double base, double exponent)
{
    return pow(base, exponent);
}
double Calculator::squareRoot(double a)
{
    return sqrt(a);
}
