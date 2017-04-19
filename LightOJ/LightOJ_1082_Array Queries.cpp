#include<iostream>
#include<stdio.h>
#include<stdlib.h>
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
#define scan(t) scanf("%d",&t)
#define scan2(x,y) scanf("%d%d",&x,&y)
#define print(t) printf("%d",t)
#define test(t) printf("Test -> %d\n",t)
#define FOR(n) for(int i=0;i<n;i++)
#define read() freopen("input.txt","r",stdin)

using namespace std;
 int input[1000000],ST[1000000];
int RangeQuery(int QL,int QR,int l,int r,int root)
{
    if(QL<=l && QR>=r)
        return ST[root];
    if(QL>r ||QR<l)
        return INT_MAX;
    int mid=(l+r)/2;
    return min(RangeQuery(QL,QR,l,mid,2*root+1),RangeQuery(QL,QR,mid+1,r,2*root+2));
}

void ConsTree(int l,int r,int root)
{

    if(r == l)
    {
        ST[root]=input[l];
        return;
    }
    int mid=(l+r)/2;

    ConsTree(l,mid,2*root+1);
    ConsTree(mid+1,r,2*root+2);
    ST[root]=min(ST[2*root+1],ST[2*root+2]);
    return;

}
int main()
{
    read();

    int t;
    scan(t);

    for(int i=1;i<=t;i++)
    {
        memset(ST,INT_MAX,sizeof(ST));
        memset(input,0,sizeof(input));
        int N,q;
        scanf("%d%d",&N,&q);
        double ND=(double)N;
        int s=ceil(log(ND)/log(2));
        s=pow(2,s);

        for(int j=0;j<N;j++)
        {
            scan(input[j]);
        }
        ConsTree(0,N-1,0);


        printf("Case %d:\n",i);
        for(int j=0;j<q;j++)
        {

            int l,r;
            scan2(l,r);
           // if(l==0 || r==0)
            printf("%d\n",RangeQuery(l-1,r-1,0,N-1,0));
        }


    }
    return 0;
}


