#include<bits/stdc++.h>
#define N 100
using namespace std;
int color[N][N];
int visited[N][N];
void print_screen(int n)
{
    for(int i=0; i<n; i++)
    {
        for( int j =0; j<n; j++)
        {
            cout << color[i][j] << " ";
        }
        cout<< endl;
    }
}
bool is_valid(int x, int y, int n)
{
    if( (x<n && x >=0) && (y<n && y >=0) && visited[x][y]==0 )
        return true;
    return false;
}
void visit(int replacement_color,int old_color, int x, int y, int n)
{

    if( is_valid( x, y, n ) && color[x][y] == old_color )
    {
        color[x][y] = replacement_color;
        visited[x][y] = 1;
        visit(replacement_color, old_color, x+1, y, n);
        visit(replacement_color, old_color, x-1, y, n);
        visit(replacement_color, old_color, x, y+1, n);
        visit(replacement_color, old_color, x, y-1, n);
    }
    return;

}
int main()
{
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for( int j=0; j<n; j++)
        {
            int col;
            cin>>col;
            color[i][j] = col;
            visited[i][j] = 0;
        }
    }
    int x,y,new_color;
    cin >> x >> y >> new_color;
    print_screen(n);
    visit( new_color,color[x][y], x, y, n );
    print_screen(n);
}
