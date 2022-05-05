#include<bits/stdc++.h>
using namespace std;

float f(float x)
{
    return 1/(1+x);
}

int main()
{
    float a,b,n;
    cout<<"Enter lower limit : ";
    cin>>a;
    cout<<"Enter upper limit : ";
    cin>>b;
    cout<<"Enter subintervals : ";
    cin>>n;

    float h = (b - a)/n;
    float ans = 0;
    float xc = a + h;
    while(xc != b && xc < b)
    {
        ans = ans + 2*f(xc);
        xc = xc + h;
    }
    ans = ans + f(a) + f(b);
    ans = ans*h/2;

    cout<<"Integrated value : "<<ans;
    return 0;
}