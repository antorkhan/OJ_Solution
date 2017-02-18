#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#define read() freopen("input.txt","r",stdin)
#define VERTEX 220

using namespace std;

bool visited[VERTEX];
int color[VERTEX];

bool BFS(vector<int> graph[],int root)
{
    queue<int> q;
    q.push(root);
    visited[root]=true;
    color[root]=0;
    int cc=1;
    bool flag=true;
    while(!q.empty())
    {

        int u=q.front();
        q.pop();
        if(color[u]==0)
            cc=1;
        else if(color[u]==1)
            cc=0;
    //    cout<<u<<" ";
        int s=graph[u].size();
        for(int v=0;v<s;v++)
        {
            if(visited[graph[u][v]]==false)
            {
                q.push(graph[u][v]);
                visited[graph[u][v]]=true;
                color[graph[u][v]]=cc;

            }
            else if(visited[graph[u][v]]==true && color[graph[u][v]]==color[u])
                return false;

        }



    }
    return flag;
}

int main()
{
    read();
    int t;

    while(cin>>t)
    {
        if(t==0)
            return 0;

        int start;
        for(int i=0;i<t+10;i++)
            visited[i]=false;

        for(int i=0;i<t+10;i++)
            color[i]=-1;

        vector<int> adj[t+10];
        int e;
        cin>>e;
        while(e--)
        {
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            start=x;
        }

        if(BFS(adj,0))
        {
            cout<<"BICOLORABLE.\n";
        }
        else
        {
            cout<<"NOT BICOLORABLE.\n";
        }
    }


}
