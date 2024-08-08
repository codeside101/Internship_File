#include <iostream>
using namespace std;


int add(int a, int b)
{

    return a + b;
}


int add(int a, int b, int c)
{

    return a + b + c;
}


double add(double a, double b)
{

    return a + b;
}

int main()
{
    int result1 = add(5, 3);        // Calls the first function
    int result2 = add(5, 3, 2);     // Calls the second function
    double result3 = add(2.5, 3.5); // Calls the third function
    cout << "Function to add two integers" << endl;
    cout << "Result of add(5, 3): " << result1 << endl;
    cout << "Function to add three integers" << endl;
    cout << "Result of add(5, 3, 2): " << result2 << endl;
    cout << "Function to add two doubles" << endl;
    cout << "Result of add(2.5, 3.5): " << result3 << endl;

    return 0;
}
