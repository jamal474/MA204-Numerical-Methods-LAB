#include<iostream>
#include<conio.h>
 
using namespace std;
 
int main(void)
{
    int n;
    cout << "Enter number of varibles : ";
    cin >> n;
    float a[n][n+1], x[10], y[10];
    int niter = 0;
    
    cout<<"Enter Augmented Matrix : "<<"\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cin >> a[i][j];
        }
    }
    
    cout << "Enter initial values of x : ";
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    cout << "Enter the no. of iteration : ";
    cin >> niter;

    cout << "Enter error tolerance : ";
    float eps,e[n];
    cin>>eps;

    while (niter > 0)
    {
        for (int i = 0; i < n; i++)
        {
            y[i] = (a[i][n] / a[i][i]);
            e[i] = x[i];
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);
                x[i] = y[i];
            }
            printf("x%d = %f    ", i + 1, y[i]);
            e[i] = e[i] - y[i];
        }
        cout << "\n";
        niter--;
        for(int i = 0;i<n;i++)
        {
            if(abs(e[i]) < eps)
            {
                niter = -1;
            }
        }
    }
    cout<<"\nSolution : ";
    for(int i = 0;i<n;i++)
    {
        cout<<y[i]<<" ";
    }
    return 0;
}