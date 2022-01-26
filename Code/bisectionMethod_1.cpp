#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

typedef long double ldb;
ldb eps = 0.0000001;

ldb f(ldb x)
{
    return pow(x,3) + 4*pow(x,2) - 10;
}

int main()
{
    ldb st = 1;
    ldb lt = 2;
    ldb value = f((st + lt)/2);
    int iteration = 0;

    while(abs(value) > eps)
    {
       iteration++;
       if(value*f(st) < 0)
       {
           lt = (st + lt)/2; 
       }
       if(value*f(lt) < 0)
       {
           st = (st + lt)/2; 
       }
       value = f((st + lt)/2);
    }
    cout<<"Root of the Equation (x^3 + 4x^2 - 10) : { x = ";
    cout<<fixed<<setprecision(3)<<(st + lt)/2<<" }"<<endl;
    cout<<"Root found in "<<iteration<<" iterations"<<endl;
    cout<<"Error % : "<<(abs(1.365 - (round(((st+lt)/2)*1000.0)/1000.0))/1.365)*100<<endl;
   
    return 0;
}