#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int arr1[3], arr2[3];
    int s = 0;
    int product = 0;
    int size1 = sizeof(arr1) / sizeof(int);
    int size2 = sizeof(arr2) / sizeof(int);
    cout << "enter the first vector" << endl;

    for (int i = 0; i < size1; i++)
        cin >> arr1[i];
    cout << "enter the second vector" << endl;
    for (int j = 0; j < size2; j++)
        cin >> arr2[j];
    for (int i = 0; i < size1; i++)
    {
        {
            product = arr1[i] * arr2[i];
            s = s + product;
        }
    }
    cout << "Dot Product=" << s;
    return 0;
}