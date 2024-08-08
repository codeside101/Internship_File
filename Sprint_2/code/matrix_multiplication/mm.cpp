#include<iostream>
using namespace std;
int main()
{
    cout<<"enter the dimension of two matrix for ex- (nxp)and(pxq) so, enter n p q value"<<endl;
    
    int n1,n2,n3;
    
    cin>>n1>>n2>>n3;
    int m1[n1][n2];
    int m2[n2][n3];
    cout<<"enter the elements of 1st matrix "<<endl;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            cin>>m1[i][j];

        }
    }
    cout<<"enter the elements of 2st matrix "<<endl;
    for(int i=0;i<n2;i++)
    {
        for(int j=0;j<n3;j++)
        {
            cin>>m2[i][j];
            
        }
    }
   int ans[n1][n3];
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n3;j++)
        {
            ans[i][j]=0;
            
        }
    }
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n3;j++)
        {
        for(int k=0;k<n2;k++)
        {
            ans[i][j]+=m1[i][k]*m2[k][j];
        }
        }
    }
    cout<<"The result of the multiplication is "<<endl;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n3;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}