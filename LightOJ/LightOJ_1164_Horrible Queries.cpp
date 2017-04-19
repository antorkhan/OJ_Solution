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
#define MAX 1000000
#define LLI long long int
#define INT_VEC vector<int>
#define scan(t) scanf("%d",&t)
#define scan2(x,y) scanf("%d%d",&x,&y)
#define print(t) printf("%d",t)
#define test(t) printf("--> Test %d\n",t)
#define NL() printf("\n")
#define FOR(n) for(int i=0;i<n;i++)
#define read() freopen("input.txt","r",stdin)

using namespace std;
LLI tree[MAX],input[MAX],lazy[MAX];
void build(int node, int start,int end)
{
    if(start==end)
        tree[node]=input[start];
    else
    {
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node +1,mid+1,end);
        tree[node]=tree[2*node]+tree[2*node +1];
    }
}
void update(int node, int left, int right, int i, int j, int value)
{
    if(i > right || j < left) return;
    if(left >= i && right <= j) lazy[node] += value;
    else
    {
        tree[node] += value*(min(j, right) - max(i, left) + 1);
        update(2*node, left, (left+right)/2, i, j, value);
        update(2*node+1, (left+right)/2+1, right, i, j, value);
    }
}
LLI query(int node,int start,int end,int l,int r)
{
    if(start>end || start>r || end<l)
        return 0;
    if(lazy[node]!=0)
    {
        tree[node]+=(end -start + 1) * lazy[node];
        if(start!=end)
        {
            lazy[node*2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node]=0;
    }

    if(start>=l && end<=r)
        return tree[node];
    int mid =(start+end)/2;
    LLI p1=query(node*2,start,mid,l,r);
    LLI p2=query(node * 2 + 1,mid+1,end,l,r);
    return (p1+p2);
}
int main()
{

    read();
//
//     update(1,0,7,0,1,100);
//     printf("%d",query(1,0,7,0,0));
    // print(tree[9]);
    int t;
    scan(t);
    for(int test=1;test<=t;test++)
    {
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));

        int n,q;
        scan2(n,q);
        build(1,0,n-1);
        printf("Case %d:\n",test);
        for(int que=0;que<q;que++)
        {

            int ty;
            scan(ty);
            if(ty)
            {
                int l,r;
                scan2(l,r);
                printf("%lld\n",query(1,0,n-1,l,r));

            }
            else
            {
                int l,r,v;
                scanf("%d %d %d",&l,&r,&v);
                update(1,0,n-1,l,r,v);
            }
        }


    }
}
