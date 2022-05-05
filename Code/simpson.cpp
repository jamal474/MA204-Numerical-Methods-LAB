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
    cout<<"Enter 2n subintervals : ";
    cin>>n;

    float h = (b - a)/n;
    float ans = 0;
    float xc = a + h;
    int index = 1;
    while(xc != b && xc <= b)
    {
        if(index%2 == 0)
        {
            ans = ans + 2*f(xc);
            index = 1;
        }
        else
        {
            ans = ans + 4*f(xc);
            index = 0;
        }
        xc = xc + h;
    }
    ans = ans + f(a);
    ans = ans*h/3;

    cout<<"Integrated value : "<<ans;
    return 0;
}