#include<iostream>

using namespace std;

int main()
{
	 double x[100],y[100][100],ip_x,ip_y;
     int n;
	 cout<<"Enter number of ordinates : ";
	 cin>>n;
	 cout<<"Enter data :"<<endl;
	 for(int i=0;i<n;i++)
	 {
		  cout<<"\tx["<< i<<"] = ";
		  cin>>x[i];
		  cout<<"\ty["<< i<<"] = ";
		  cin>>y[i][0];
          cout<<"\n";
	 }
	 cout<<"Enter interpolation point: ";
	 cin>>ip_x;
     for (int i = 1; i < n; i++) 
     {
        for (int j = 0; j < n - i; j++) 
        {
            y[j][i] = (y[j][i - 1] - y[j + 1][i - 1])/(x[j] - x[i + j]);
        }
    }

    ip_y = y[0][0];
  
    for (int i = 1; i < n; i++) 
    {
        float temp = 1;
        for (int j = 0; j < i; j++) 
        {
            temp = temp * (ip_x - x[j]);
        }
        ip_y = ip_y + temp*y[0][i];
    }
	 cout<<endl<<"Interpolated value at "<< ip_x<< " using Newton divided difference is "<< ip_y;
	 return 0;
}