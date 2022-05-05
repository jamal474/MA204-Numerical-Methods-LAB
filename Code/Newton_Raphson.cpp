#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

//equation --> f(x) = x^3 - 9x + 1

double f(double x)
{
    return pow(x,3) - 9*x + 1;
}

double df(double x)
{
    return 3*pow(x,2) - 9;
}

int main()
{
    cout<<fixed<<setprecision(8);

    double x0 = 0.0;
    cout<<"Enter the Initial guess : ";
    cin>>x0 ;


    int iteration = 0,temp = 0;
    cout<<"Enter Number of iterations : ";
    cin>>iteration;
    temp = iteration;

    double tolerance = 0.0;
    cout<<"Enter tolerance level : ";
    cin>>tolerance;

    double c = 0.0;
    
    cout<<"Iteration"<<"\t"<<"Root"<<"\t\t"<<"F(c)"<<"\n";
    do
    {
        c = x0 -  f(x0)/df(x0);
        cout<<" "<<temp - iteration + 1<<"\t\t"<<c<<"\t\t"<<f(c)<<"\n";
        x0 = c;

    } while(iteration-- && abs(f(c)) > tolerance);

    cout<<"\nRoot : "<<c<<"\n";

}
