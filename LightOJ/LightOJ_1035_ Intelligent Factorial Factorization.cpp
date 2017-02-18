#include<iostream>
#include <stdio.h>
using namespace std;


int factor[101][101];
int result[100];
void prime_factors(int n)
{
    int x=2;
    int temp=n;
    while(temp!=1 && x<=n)
    {
        if(temp%x==0)
        {
            factor[n][x]++;
            temp=temp/x;
        }
        else
            x++;


    }
}
int main()
{
    //freopen ("input.txt","r",stdin);
    for(int i=2;i<=100;i++)
        prime_factors(i);
    int t,n;
    int case_number=1;
    cin>>t;
    bool flag=true;
    while(t--)
    {
        cin>>n;
        for(int i=n;i>=2;i--)
        {
            for(int j=2;j<=100;j++)
            {
                result[j]+=factor[i][j];
            }
        }

        if(flag==true)
        {
            cout<<"Case "<<case_number<<": "<<n<<" = ";
            flag=false;
        }
        else
            cout<<"\nCase "<<case_number<<": "<<n<<" =";

        flag=true;

        for(int i=2;i<101;i++)
        {
            if(result[i]!=0 and flag==true)
            {
                cout<<""<<i<<" ("<<result[i]<<")";
                result[i]=0;
                flag=false;
            }
            else if(result[i]!=0 and flag==false)
            {
                cout<<" * "<<i<<" ("<<result[i]<<")";
                result[i]=0;

            }
        }
        cout<<"\n";
        case_number++;
        flag=true;
    }

    //fclose (stdin);
}
