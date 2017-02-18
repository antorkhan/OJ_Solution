#include<bits/stdc++.h>
#define MAX 220
#define LLI long long int
#define INT_VEC vector<int>
#define scan(t) scanf("%d",&t)
#define print(t) printf("%d",t)

#define FOR(n) for(int i=0;i<n;i++)
#define read() freopen("input.txt","r",stdin)

using namespace std;
int v[MAX][MAX];
int ans[MAX][MAX];
int find_max(int n_max,int n_car,int index,int t)
{
//    if(ans[n_car-1][index]!=-1) return ans[n_car-1][index];
    if(n_car>t)
    {
        if(index > n_max-n_car || index<0)
            return 0;
        else
        {
            if(ans[n_car-1][index]!=-1) return ans[n_car-1][index];
            ans[n_car-1][index]=v[n_car-1][index]+max(find_max(n_max,n_car+1,index-1,t),find_max(n_max,n_car+1,index,t));
            return  ans[n_car-1][index];
        }
    }
    else
    {
        if((n_car>n_max) || (index>=n_car))
            return 0;

        else
        {
            if(n_car==t)
            {
                if(ans[n_car-1][index]!=-1) return ans[n_car-1][index];
                ans[n_car-1][index]=v[n_car-1][index]+max(find_max(n_max,n_car+1,index-1,t),find_max(n_max,n_car+1,index,t));
                return  ans[n_car-1][index];
            }


            else
            {
                if(ans[n_car-1][index]!=-1) return ans[n_car-1][index];
                ans[n_car-1][index]=v[n_car-1][index]+max(find_max(n_max,n_car+1,index,t),find_max(n_max,n_car+1,index+1,t));
                return  ans[n_car-1][index];
            }
        }
    }
}
int main()
{
    read();
    int t;
    scan(t);
    for(int ii=1; ii<=t; ii++)
    {

        memset(ans,-1,sizeof(ans));
        int n;
        scan(n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=i; j++)
            {
                int temp;
                scan(temp);
                v[i][j]=temp;
            }
        }
        int k=1;
        for(int i=n-1; i>=0; i--,k++)
        {

            for(int j=0; j<i; j++)
            {

                int temp;
                scan(temp);
                 v[n+k-1][j]=temp;

            }
        }


        printf("Case %d: %d\n",ii,find_max((n*2)-1,1,0,n));
        memset(v,0,sizeof(v));

    }

}


