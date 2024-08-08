#include<iostream>
using namespace std;
int main()
{
 int a[3],b[3], sum(0),prod;
 cout << "enter the first vector" << endl;

    for (int i = 0; i <3; i++)
      { cin >> a[i];
      }
      cout << "enter the second vector" << endl;

    for (int i = 0; i < 3; i++)
      {  cin >> b[i];
      }
      char op;
    cout << "enter the operation you want" << endl;
    cin >> op;
    switch (op)
    {
        case 'd':

        for(int i=0; i<3;i++)
        {
            prod=a[i]*b[i];
            sum+=prod;
        }
        cout<<"dot product=";
        cout<<sum<<endl;
        break;
        case 'c':
        // cross product of vectors......
        int x,y,z;
        x=a[1]*b[2]-b[1]*a[2];
        y=a[0]*b[2]-b[0]*a[2];
        z=a[0]*b[1]-b[0]*a[1];
        cout<<"cross product"<<endl;
        cout<<x<<"i "<<y<<"j "<<z<<"k ";
        break;
        default:
        cout << "I am still improving";
    }

        return 0;
        }