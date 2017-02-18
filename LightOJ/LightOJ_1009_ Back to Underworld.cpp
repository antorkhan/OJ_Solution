#include<bits/stdc++.h>
#define scan(t) scanf("%d",&t)
#define scan2(t,u) scanf("%d%d",&t,&u)
#define print(t) printf("%d",t)
#define FOR(n) for(int e=0;e<n;e++)
#define VERTEX 20090
#define read() freopen("input.txt","r",stdin)

using namespace std;
bool visited[VERTEX];
int percolor[VERTEX];

long long int Get_Maximum(vector<int> graph[],int root)
{
    memset(percolor,-1,sizeof(percolor));
    stack<int> q;
    q.push(root);
    long long int color[2];
    color[0]=1;
    percolor[root]=0;
    color[1]=0;
    visited[root]=true;
    int cc=0;
    while(!q.empty())
    {
        int u=q.top();
        q.pop();
        if(percolor[u]==0)
            cc=1;
        else
            cc=0;

        int s=graph[u].size();
        for(int v=0; v<s; v++)
        {
            if(!visited[graph[u][v]])
            {
                visited[graph[u][v]]=true;
                color[cc]++;
                q.push(graph[u][v]);
                percolor[graph[u][v]]=cc;

            }
        }
    }
   //   cout<<"max -> "<<max(color[0],color[1])<<" root-> "<<root<<endl;
    return max(color[0],color[1]);
}

int main()
{
    read();
    int t;
    scan(t);
    for(int i=1; i<=t; i++)
    {
        int maxi=0;
        memset(visited,false,sizeof(visited));
        vector<int> graph[VERTEX];
        int e;
        scan(e);
        for(int k=0; k<e; k++)
        {
            int u,v;
            scan2(u,v);
            graph[u].push_back(v);
            graph[v].push_back(u);
            if(u>maxi)
                maxi=u;
            if(v>maxi)
                maxi=v;
        }
        long long int ans=0;
        for(int p=1; p<=maxi; p++)
            if(!visited[p] && graph[p].size()>0)
                ans+=Get_Maximum(graph,p);


        printf("Case %d: %lld\n",i,ans);
    }

}
