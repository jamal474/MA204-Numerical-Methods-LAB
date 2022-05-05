#include<bits/stdc++.h>
using namespace std;

float dydx(float x, float y)
{
	return y-x;
}

float RK(float x, float y, float x_req, float h,int iter)
{
	float k1, k2, k3, k4, k5;
	float ym = y;
	while(iter && x != x_req)
    {
		k1 = h*dydx(x, ym);
		k2 = h*dydx(x + 0.5*h, ym + 0.5*k1);
		k3 = h*dydx(x + 0.5*h, ym + 0.5*k2);
		k4 = h*dydx(x + h, ym + k3);

		ym = ym + (k1 + 2*k2 + 2*k3 + k4)/6;
		x = x + h;
        iter--;
	}

	return ym;
}

int main()
{
	float x , y , x_req , h;
    int iter;
    cout<<"Enter initial point and value (x,y) : ";
    cin>>x>>y;
    cout<<"Enter number of iterations : ";
    cin>>iter;
    cout<<"Enter step length (h) : ";
    cin>>h;
    cout<<"Enter x : ";
    cin>>x_req;

    float y_h = RK(x, y, x_req, h,iter);
    float y_h_by_2 = RK(x, y, x_req, h/2,iter);
    cout<<"\nThe value of y at "<<x_req<<" is :-"<<endl;
    cout<<"\t h : "<<y_h<<endl;
    cout<<"\t h/2 : "<<y_h_by_2<<endl;
	cout<<"Truncation error : "<<abs(y_h - y_h_by_2);


	return 0;
}
