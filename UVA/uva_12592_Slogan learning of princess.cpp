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
   // read();
    int N;
    cin>>N;
    map<string,string>  mp;

    for(int i=0; i<N; i++)
    {
        char d;
        if(i==0)
            scanf("%c",&d);
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        mp[s1]=s2;
      //  cout<<s1<<'\n'<<mp[s1]<<'\n';

    }

    int Q;
    cin>>Q;

    for(int i=0; i<Q; i++)
    {
        char d;
        if(i==0)
            scanf("%c",&d);
        string s1;
        getline(cin,s1);
        cout<<mp[s1]<<'\n';
    }


}


