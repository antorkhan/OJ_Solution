#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
#define MAX 10000
#define LLI long long int
#define INT_VEC vector<int>
#define read() freopen("input.txt","r",stdin)

using namespace std;
bool check(INT_VEC v)
{
    bool flag=true;
    stack<int> s;
    int l=v.size();
    if(l<=2)
        return true;
    int start=0;
    for(int i=1;i<=l;i++)
    {
        if(i==v[start])
        {
            start++;
            while(!s.empty() && s.top()==v[start])
            {
                s.pop();
                start++;
            }
        }
        else
        {
            s.push(i);
        }
    }
    if(s.empty())
    {
        return true;
    }
    return false;

}
int main()
{
    read();
    int cn;
    bool flag;
     INT_VEC v;
    while(cin>>cn && cn!=0)
    {
        flag=true;

        while(1)
        {

            for(int i=0;i<cn;i++)
            {
                int d;
                cin>>d;
                if(d==0)
                {
                    cout<<"\n";
                    flag=false;
                    break;
                }

                v.push_back(d);
            }


            if(flag==false)
                break;
            if(check(v))
            {
                cout<<"Yes\n";
            }
            else
            {
                cout<<"No\n";
            }
            v.clear();
        }
    }
}


