#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    const long double pi = 3.141592653589793;
    float x;
    float g;
    cout << "enter the angle of rotation"<<endl;
    cin >> g;
    x = (g * pi) / 180;
    float a, b,c,d;
    a = cos(x);
    b = -sin(x);
    c = sin(x);
    d = cos(x);

    int m1[2][2];
    int m2[2][1];

    m1[0][0] = a;
    m1[0][1] = b;
    m1[1][0] = c;
    m1[1][1] = d;
cout << "Enter the 2D vector for rotation"<<endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            cin >> m2[i][j];
        }
    }
    int ans[2][1];
    ans[0][0] = m1[0][0] * m2[0][0] - m1[0][1] * m2[1][0];
    ans[1][0] = m1[1][0] * m2[0][0] - m1[1][1] * m2[1][0];
cout << "Rotated 2D vector"<<endl;
   for(int i=0;i<2;i++)
    {
        for(int j=0;j<1;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

return 0;
}