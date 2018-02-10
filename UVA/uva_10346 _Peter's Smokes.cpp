#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
#include<limits.h>


#define MAX 10000
#define LLI long long int
#define INT_VEC vector<int>
#define scanint(t) scanf("%d",&t)
#define scanfloat(t) scanf("%f",&t)
#define scandouble(t) scanf("%lf",&t)
#define scan2(x,y) scanf("%d%d",&x,&y)
#define print(t) printf("%d",t)
#define test(t) printf("--> Test %d\n",t)
#define NL() printf("\n")
#define FOR(i,n) for(i=0;i<n;i++)
#define pb push_back
#define read() freopen("input.txt","r",stdin)

using namespace std;
int main()
{
    read();
    int n,k;
    while(cin>>n>>k)
    {
        int ans=n;
        while(n>=k)
        {
            ans+=n/k;
            n=(n/k)+(n%k);
        }
        cout<<ans<<'\n';
    }



}

