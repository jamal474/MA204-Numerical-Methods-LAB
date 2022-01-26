#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

typedef long double ldb;
ldb eps = 0.00000000001;
#define pi 3.14159265358979323846

ldb f(ldb x)
{
    return cos(x) - x*exp(x);
}

int main()
{
    ldb st = 0;
    ldb lt = ldb(pi)/2;
    int iteration = 0;
    ldb value = f((st + lt)/2);
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
    cout<<"Root of the Equation (cos(x) - xe^x) : { x = ";
    cout<<fixed<<setprecision(3)<<(st + lt)/2<<" }"<<endl;
    cout<<"Root found in "<<iteration<<" iterations";
    return 0;
}