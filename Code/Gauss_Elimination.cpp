#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{

    int size;
    double A[10][10],x[10]={0};
	double p,temp;

    cout<<"Enter number of variables : ";
    cin>>size;
    cout<<"Enter Augmented Matrix : \n";
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<=size;j++)
		{
            cin>>A[i][j];
		}
    }
    
    //Gauss Elimination
    for(int k=0;k<size-1;k++)
	{
		//Partial Pivoting
		for(int i=size-1;i>k;i--)        
    	{
        	if(A[i-1][0]<A[i][0])
            	for(int j=0;j<=size;j++)
            	{
                	temp=A[i][j];
                	A[i][j]=A[i-1][j];
                	A[i-1][j]=temp;
            	}
    	}

		//
        for(int i=k;i<size-1;i++)
        {
            p = (A[i+1][k]/A[k][k]) ;
            for(int j=0;j<=size;j++)
			{
                A[i+1][j]-=p*A[k][j];
			}
        }
	}
	double c = 0;
    //Backward Substitution
    for(int i=size-1;i>=0;i--)
    {
        c=0;
        for(int j=i;j<=size-1;j++)
            c=c+A[i][j]*x[j];

        x[i]=(A[i][size]-c)/A[i][i];
    }

	cout<<"Solution : "<<endl;
    for(int i=0;i<size;i++)
	{
    	cout<<"x["<<i<<"] : "<<x[i]<<endl;
	}

    return 0;
}