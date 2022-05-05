#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

//equation --> f(x) = x^3 - 9x + 1

double f(double x)
{
    return cos(x) - x*exp(x);
}

int main()
{
    cout<<fixed<<setprecision(8);

    double begng,end= 0.0;
    cout<<"Enter the Endpoints : ";
    cin>>begng>>end;


    int iteration = 0,temp = 0;
    cout<<"Enter Number of iterations : ";
    cin>>iteration;
    temp = iteration;

    double tolerance = 0.0;
    cout<<"Enter tolerance level : ";
    cin>>tolerance;

    double c = (begng*f(end) - end*f(begng))/(f(end) - f(begng));
    cout<<"Iteration"<<"\t"<<"Root"<<"\t\t"<<"F(c)"<<"\n";
    while(iteration-- && abs(f(c)) > tolerance)
    {
        if(f(begng) * f(c) < 0)
        {
            end = c;
        }
        else
        {
            begng = c;
        } 
        cout<<" "<<temp - iteration<<"\t\t"<<c<<"\t\t"<<f(c)<<"\n";
        c = (begng*f(end) - end*f(begng))/(f(end) - f(begng));
    }

    cout<<"\nRoot : "<<c<<"\n";

}
