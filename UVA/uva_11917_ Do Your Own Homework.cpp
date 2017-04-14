#include<bits/stdc++.h>
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
    //read();
    int t;
    scanint(t);
    for(int i=1;i<=t;i++)
    {
        unordered_map<string,int> um;
        int course;
        scanint(course);
        for(int j=0;j<course;j++)
        {
            string s;
            int time;
            cin>>s>>time;
            um[s]=time;
        }
        int D;
        scanint(D);
        string preferred;
        cin>>preferred;
        if(um[preferred]==0 || um[preferred]>D+5 )
            printf("Case %d: Do your own homework!\n",i);
        else if(um[preferred]<=D)
            printf("Case %d: Yesss\n",i);
        else
             printf("Case %d: Late\n",i);
    }
}

