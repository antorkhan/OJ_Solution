#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{

    int t;
    cin >>t;
    while(t--)
    {

        double  x,y,dollar;
        cin>>x>>y>>dollar;
        double z=(x+y)/3;

        x=x-z;
        y=y-z;
        double ph=dollar/(x+y);
        double ans= x*ph;
         printf("%.0lf\n",ans);
      //  cout<<ans<<"\n";
    }
}
