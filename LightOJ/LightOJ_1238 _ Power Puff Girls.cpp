#include<bits/stdc++.h>
using namespace std;

int M,N;
int ar,ac,br,bc,cr,cc,hr,hc;
char grid[30][30];
bool marked[30][30];

struct State
{
    int x,y;
    int moves;

};

vector<State> v;

void getNeighbours(State &s)
{
    int x=s.x;
    int y=s.y;

    if(x+1<M && grid[x+1][y]!='#' && grid[x+1][y]!='m')
    {
        State temp=s;
        temp.x++;
        temp.moves++;
        v.push_back(temp);

    }

    if(y+1<N && grid[x][y+1]!='#' && grid[x][y+1]!='m')
    {

        State temp=s;
        temp.y++;
        temp.moves++;
        v.push_back(temp);

    }
    if(x-1>=0 && grid[x-1][y]!='#' && grid[x-1][y]!='m')
    {
        State temp=s;
        temp.x--;
        temp.moves++;
        v.push_back(temp);


    }
    if(y-1>=0 && grid[x][y-1]!='#' && grid[x][y-1]!='m')
    {
        State temp=s;
        temp.y--;
        temp.moves++;
        v.push_back(temp);

    }



}
bool isTrue(State &t)
{
    if(t.x==hr && t.y==hc) return true;
    return false;
}

int bfs(int x,int y)
{
    memset(marked,false,sizeof(marked));
    queue<State> stk;
    State t;
    t.x=x;
    t.y=y;
    t.moves=0;
    stk.push(t);
    marked[t.x][t.y]=true;


    while(!stk.empty())
    {

        State t=stk.front();
        stk.pop();
        if(isTrue(t))
        {
            v.clear();
            return t.moves;
        }
        else
        {
            getNeighbours(t);
            for(int i=0; i<v.size(); i++)
            {

                if(!marked[v[i].x][v[i].y])
                {
                    marked[v[i].x][v[i].y]=true;
                    stk.push(v[i]);
                }

            }

            v.clear();
        }

    }
    return -1;

}

int main()
{
    freopen("input.txt","r",stdin);
    int t;
    cin>>t;


    for(int ca=1; ca<=t; ca++)
    {
        string s[200];
        cin>>M>>N;
        getchar();
        for(int i=0;i<M;i++) cin>>s[i];
     //   for(int i=0;i<M;i++) cout<<s[i]<<endl;
        for(int i=0; i<M; i++)
        {

            for(int j=0; j<N; j++)
            {

                grid[i][j]=s[i][j];
                if(grid[i][j]=='a')
                {
                    ar=i;
                    ac=j;
                }
                else if(grid[i][j]=='b')
                {
                    br=i;
                    bc=j;
                }
                else if(grid[i][j]=='c')
                {
                    cr=i;
                    cc=j;
                }
                else if(grid[i][j]=='h')
                {
                    hr=i;
                    hc=j;
                }
            }

        }


        int score_a=bfs(ar,ac);
        int score_b=bfs(br,bc);
        int score_c=bfs(cr,cc);

        int m;
        if(score_a>=score_b && score_a>=score_c)
            m=score_a;
        else if(score_b>=score_a && score_b>=score_c)
            m=score_b;
        else
            m=score_c;
        printf("Case %d: %d\n",ca,m);


    }
}

