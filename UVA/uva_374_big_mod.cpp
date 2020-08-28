#include<bits/stdc++.h>
using namespace std;
int big_mod(int b,int p, int m)
{
    if(p == 0)
        return 1;
    else if( p%2 == 1 )
    {
        return ((b%m) * big_mod( b, p-1, m ))%m;
    }
    else
    {
        return ((big_mod(b,p/2,m)% m) * (big_mod(b,p/2,m)% m)) %m;
    }

}
int main()
{
    //freopen("input.txt","r",stdin);
    int B,P,M;

    while(scanf("%d%d%d",&B,&P,&M) != EOF)
    {
        //printf("%d%d%d",B,P,M);
        cout << big_mod(B,P,M)<< endl;
    }
    return 0;
}
