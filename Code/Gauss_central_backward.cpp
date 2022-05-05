#include<bits/stdc++.h>
using namespace std;

float p_cal(float p,int n)
{
    float temp = p;
    for(int i =1;i<n;i++)
    {
        if(i%2 == 1 )
        {
            temp = temp * (p + (i+ 1)/2);
        }
        else
        {
            temp = temp * (p - i/2);
        }
    }
    return temp;
}

int fact(int n)
{
    int f = 1;
    for(int i = 2;i<n+1;i++)
    {
        f *= i;
    }
    return f;
}

int main()
{
    float p,value,sum = 0;
    int n = 0;
    cout<<"Enter number of data points : ";
    cin>>n;

    vector<float> x(n);
    vector<vector<float>> y(n);
    for(int i = 0;i<n;i++)
    {
        y[i] = vector<float>(n);
    }

    cout<<"Enter data : \n";
    for(int i = 0;i<n;i++)
    {
        cin>>x[i]>>y[i][0];
    }

    for(int i = 1;i<n;i++)
    {
        for(int j = 0;j<n-i;j++)
        {
            y[j][i] = round((y[j + 1][i - 1] - y[j][i - 1])*10000)/10000;
        }
    }
    
    for(int i = 0;i<n;i++)
    {
        cout<<x[i]<<"\t";
        for(int j = 0;j<n-i;j++)
        {
            cout<<y[i][j]<<"\t";
        }
        cout<<"\n";
    }
        cout<<"Enter x_inter : ";
        cin>>value;
 

    sum = y[int(n/2)][0];
    p = (value - x[n/2]) / (x[1] - x[0]);
 
    for (int i = 1;i<n;i++)
    {
        sum = sum + (p_cal(p, i) * y[floor(float(n-i)/2)][i])/fact(i);
        cout<<(p_cal(p, i) * y[floor(float(n-i-1)/2)][i])/fact(i)<<"\n";
    }
    cout<<"Y value : "<<sum;
    return 0;
}
