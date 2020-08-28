#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<algorithm>
#include<map>
#define MAX 10000
using namespace std;
vector<int> adj[MAX];
map<int,int> mp;
int visited[MAX];
int dist[MAX];
int p[MAX];

void bfs(vector<int> adj[],int s,int t,int n)
{
    for(int i=0;i<n;i++)
        visited[i]=0;

    queue<int> Q;
    Q.push(s);
    visited[s]=1;
    dist[s]=0;
    p[s]=s;
    while(!Q.empty())
    {

        int u=Q.front();
        Q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            if(visited[adj[u][i]]==0)
            {
                int v=adj[u][i];
                visited[v]=1;
                dist[v]=dist[u]+1;
                p[v]=u;
                Q.push(v);
            }
        }
    }
    if(visited[t]==0)
    {
        return;
    }
    vector<int> path;
    path.push_back(t);
    int now=t;
    while(now!=s)
    {
        now=p[now];
        path.push_back(now);
       // cout<<"here?";

    }
    int l=path.size();

    for(int i=l-1;i>=0;i--)
    {
        char c=path[i]+'A';
        cout<<c;

    }
    cout<<endl;
}
int main()
{
   // freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    int ca;
    scanf("%c",&ca);
    while(t--)
    {
        vector<int> adj[MAX];

        int edge,query,city=0;
        cin>>edge>>query;
        while(edge--)
        {
            string us,vs;
            cin>>us>>vs;
            int u = us[0]-'A';
            int v = vs[0]-'A';
            adj[u].push_back(v);
            adj[v].push_back(u);
            if(mp[u]==0)
            {
                mp[u]=1;
                city++;
            }
             if(mp[v]==0)
            {
                mp[v]=1;
                city++;
            }



        }
        for(int i=0;i<query;i++)
        {
            string us,vs;
            cin>>us>>vs;
            int u = us[0]-'A';
            int v = vs[0]-'A';
            bfs(adj,u,v,MAX);


        }
        if(t!=0)
            cout<<endl;
        mp.clear();
    }
}
