#include <iostream>

#include "calculator.h"

int main()
{
    Calculator calc;

    double result = calc.add(5.0, 3.0);
    std::cout << "5 + 3 = " << result << std::endl;

    result = calc.subtract(7.0, 2.0);
    std::cout << "7 - 2 = " << result << std::endl;

    result = calc.multiply(4.0, 6.0);
    std::cout << "4 * 6 = " << result << std::endl;

    result = calc.divide(8.0, 0.0);
    std::cout << "8 / 0 = " << result << std::endl;

    result = calc.square(5.0);
    std::cout << "Square of 5 = " << result << std::endl;

    result = calc.cube(3.0);
    std::cout << "Cube of 3 = " << result << std::endl;

    result = calc.power(2.0, 5.0);
    std::cout << "2^5 = " << result << std::endl;

    result = calc.squareRoot(25.0);
    std::cout << "Square root of 25 = " << result << std::endl;

    std::cout << "Hello" << std::endl;

    return 0;
}
