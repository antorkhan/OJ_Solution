#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#define MAX 10000
#define LLI long long int
#define INT_VEC vector<int>

using namespace std;
char tictac[4][4];
bool isAvailable(int x,int y)
{
    if(x>=4 || y>=4 || y<0 || x<0)
        return false;
    else if(tictac[x][y]=='o')
        return false;
    else if(tictac[x][y]=='.')
        return true;

    return false;
}
bool isAvailable2(int x,int y)
{
    if(x>=4 || y>=4 || y<0 || x<0)
        return false;
    else if(tictac[x][y]=='o')
        return false;
    else if(tictac[x][y]=='x')
        return true;
    else
        return false;
}
bool checkRight(int x,int y)
{
    bool result=false;
    if(tictac[x][y+1]=='x')
    {
        result=isAvailable(x,y+2);
        if(result==true)
            return result;
    }
    else if(tictac[x][y+1]=='.')
    {
        result=isAvailable2(x,y+2);
        if(result==true)
            return result;
    }

    return result;
}
bool checkLeft(int x,int y)
{
    bool result=false;
    if(tictac[x][y-1]=='x')
    {
        result=isAvailable(x,y-2);
        if(result==true)
            return result;
    }
    else if(tictac[x][y-1]=='.')
    {
        result=isAvailable2(x,y-2);
        if(result==true)
            return result;
    }
    return result;
}
bool checkUp(int x,int y)
{
    bool result=false;
    if(tictac[x-1][y]=='x')
    {
        result=isAvailable(x-2,y);
        if(result==true)
            return result;
    }
    else if(tictac[x-1][y]=='.')
    {
        result=isAvailable2(x-2,y);
        if(result==true)
            return result;
    }
    return result;
}
bool checkDown(int x,int y)
{
    bool result=false;
    if(tictac[x+1][y]=='x')
    {
        result=isAvailable(x+2,y);
        if(result==true)
            return result;
    }
    else if(tictac[x+1][y]=='.')
    {
        result=isAvailable2(x+2,y);
        if(result==true)
            return result;
    }
    return result;
}
bool checkRightUp(int x,int y)
{
    bool result=false;
    if(tictac[x-1][y+1]=='x')
    {
        result=isAvailable(x-2,y+2);
        if(result==true)
            return result;
    }
    else if(tictac[x-1][y+1]=='.')
    {
        result=isAvailable2(x-2,y+2);
        if(result==true)
            return result;
    }
    return result;
}
bool checkLeftUp(int x,int y)
{
    bool result=false;
    if(tictac[x-1][y-1]=='x')
    {
        result=isAvailable(x-2,y-2);
        if(result==true)
            return result;
    }
    else if(tictac[x-1][y-1]=='.')
    {
        result=isAvailable2(x-2,y-2);
        if(result==true)
            return result;
    }
    return result;
}
bool checkRightDown(int x,int y)
{
    bool result=false;
    if(tictac[x+1][y+1]=='x')
    {
        result=isAvailable(x+2,y+2);
        if(result==true)
            return result;
    }
    else if(tictac[x+1][y+1]=='.')
    {
        result=isAvailable2(x+2,y+2);
        if(result==true)
            return result;
    }
    return result;
}
bool checkLeftDown(int x,int y)
{
    bool result=false;
    if(tictac[x+1][y-1]=='x')
    {
        result=isAvailable(x+2,y-2);
        if(result==true)
            return result;
    }
    else if(tictac[x+1][y-1]=='.')
    {
        result=isAvailable2(x+2,y-2);
        if(result==true)
            return result;
    }
    return result;
}
int main()
{

    int counts=0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
             cin>>tictac[i][j];
           // scanf("%c",&tictac[i][j]);
            if(tictac[i][j]=='o')
                counts++;
        }
    }

    if(counts<2)
        cout<<"NO";
    else
    {

        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                bool flags[8];
                for(int x=0; x<8; x++)
                    flags[x]=false;
                if(tictac[i][j]=='x')
                {
                    flags[0]=checkLeft(i,j);
                    flags[1]=checkRight(i,j);
                    flags[2]=checkUp(i,j);
                    flags[3]=checkDown(i,j);
                    flags[4]=checkRightUp(i,j);
                    flags[5]=checkRightDown(i,j);
                    flags[6]=checkLeftUp(i,j);
                    flags[7]=checkLeftDown(i,j);
                    if(flags[0]==true || flags[1]==true || flags[2]==true || flags[3]==true || flags[4]==true || flags[5]==true || flags[6]==true || flags[7]==true )
                    {
                        cout<<"YES";
                        return 0;
                    }
                }


            }
        }
        cout<<"NO";
    }
}


