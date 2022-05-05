#include<iostream>

using namespace std;

int main()
{
	 double x[100], y[100], ip_x, ip_y=0, temp;
     int n;
	 cout<<"Enter number of ordinates : ";
	 cin>>n;
	 cout<<"Enter data :"<< endl;
	 for(int i=0;i<n;i++)
	 {
		  cout<<"\tx["<< i<<"] = ";
		  cin>>x[i];
		  cout<<"\ty["<< i<<"] = ";
		  cin>>y[i];
          cout<<"\n";
	 }
	 cout<<"Enter interpolation point: ";
	 cin>>ip_x;

	 /* Implementing Lagrange Interpolation */
	 for(int i=0;i<n;i++)
	 {
		  temp = 1;
		  for(int j=0;j<n;j++)
		  {
			   if(i!=j)
			   {
			    	temp = temp*(ip_x - x[j])/(x[i] - x[j]);
			   }
		  }
		  ip_y = ip_y + temp*y[i];
	 }
	 cout<< endl<<"Interpolated value at "<< ip_x<< " is "<< ip_y;

	 return 0;
}