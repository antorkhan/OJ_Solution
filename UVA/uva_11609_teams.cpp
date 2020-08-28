#include<bits/stdc++.h>
using namespace std;
long long int big_mod(long long x, long long y, long long mod)
{
    long long r = 1, z = x;
    while(y)
    {
        if(y&1)
            r = r*z, r %= mod;
        y >>= 1;
        z = z*z, z %= mod;
    }
    return r;

}
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    long long answer;
    cin >> T;
    for(int cases = 1; cases <= T; cases++)
    {
        int N;
        cin >> N;
        answer = (N * big_mod(2,N-1,1000000007))% 1000000007;
        printf("Case #%d: %lld\n",cases,answer);
    }


}
