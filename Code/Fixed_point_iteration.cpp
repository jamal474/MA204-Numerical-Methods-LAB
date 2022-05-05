#include<bits/stdc++.h>
using namespace std;

float f(float x)
{
    return x*x*x - 3*x + 1;
}

int main()
{
    float a;
    cout<<"Enter Initial guess ( a ) : ";
    cin>>a;
    int iter = 0;
    cout<<"Enter number of iteration : ";
    cin>>iter;
    cout<<"Enter Tolerance : ";
    float eps = 0.0;
    cin>>eps;

    float c = f(a);
    float y = f(c);
    while(iter-- && abs(y) > eps)
    {
        //cout<<c<<"\n";
        c = f(c);
        //cout<<c<<"\n";
        y = f(c);
        //cout<<y<<"\n";
    }
    cout<<"Root : "<<c<<" Iter  : "<<iter;
    return 0;
}