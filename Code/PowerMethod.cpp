#include<iostream>
#include<algorithm>


using namespace std;

int main()
{
    int n,step = 1;
    cout<<"Enter Order of Matrix : ";
    cin>>n;
    float a[n][n],x[n],c[n],d=0,temp;
    cout<<"Enter Matrix elements : \n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }

    cout<<"Enter initial guess vector : ";
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }


    do
    {
        for(int i=0;i<n;i++)
        {
            c[i]=0;
            for(int j=0;j<n;j++)
                c[i]+=a[i][j]*x[j];
        }

        //new vector
        for(int i=0;i<n;i++)
        {
            x[i]=c[i];
        }
            
        temp=d;
        d=0;
        //scaling
        d = max(abs(*max_element(x,x+n)),abs(*min_element(x,x+n)));
        for(int i=0;i<n;i++)
        {
            x[i] = x[i]/d;
        }
        cout<<"Step : "<<step++<<"\n";
        cout<<"Eigen value : "<<d<<endl;
    
        cout<<"Eigenvector : [";
        for(int i=0;i<n;i++)
        {
            cout<<x[i];
            if(i != n-1)
            {
                cout<<" ; ";
            }
        }
        cout<<"]\n\n";

            
    }while(abs(d-temp)>0.00001);
    return 0;
}
