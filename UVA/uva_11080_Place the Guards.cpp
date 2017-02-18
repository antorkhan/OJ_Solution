#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#define read() freopen("input.txt","r",stdin)
#define VERTEX 300

using namespace std;

bool visited[VERTEX];
int color[VERTEX];
vector<int> adj[VERTEX];

int BFS(vector<int> graph[],int root)
{
    queue<int> q;
    q.push(root);
    visited[root]=true;
    int co[2]={0,0};
    color[root]=0;
    int cc=1;
    co[0]++;
    //bool flag=true;
//    int co[2];
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
        if(s==0)
            return 1;
        for(int v=0;v<s;v++)
        {
            if(visited[graph[u][v]]==false)
            {
                q.push(graph[u][v]);
                visited[graph[u][v]]=true;
                color[graph[u][v]]=cc;
                co[cc]++;

            }
            else if(visited[graph[u][v]]==true && color[graph[u][v]]==color[u])
                return -1;

        }



    }
  //  cout<<co[0] <<"c0 "<<co[1]<<endl;
    if(co[0]< co[1])
        return co[0];
    return co[1];
}

int main()
{
    //read();
    int t;
    cin>>t;
    while(t--)
    {

        int start;
        for(int i=0;i<VERTEX;i++)
            visited[i]=false;

        for(int i=0;i<VERTEX;i++)
            color[i]=-1;
        for(int i= 0; i < VERTEX; i++){
            adj[i].clear();
        }
        int v,e;
        cin>>v>>e;
        for(int i=0;i<e;i++)
        {
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            start=x;
        }
        long long int out=0;
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false)
            {
                int temp;
                temp=BFS(adj,i);
                if(temp!=-1)
                {
                    out+=temp;
                }
                else
                {
                    out=-1;
                    break;
                }

            }
        }

        cout<<out<<endl;
    }


}

