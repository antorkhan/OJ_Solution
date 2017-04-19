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


#define MAX 10000
#define LLI long long int
#define INT_VEC vector<int>
#define scanint(t) scanf("%d",&t)
#define scanfloat(t) scanf("%f",&t)
#define scandouble(t) scanf("%lf",&t)
#define scan2(x,y) scanf("%d%d",&x,&y)
#define print(t) printf("%d",t)
#define test(t) printf("--> Test %d\n",t)
#define NL() printf("\n")
#define FOR(i,n) for(i=0;i<n;i++)
#define pb push_back
#define read() freopen("input.txt","r",stdin)

using namespace std;
int main()
{
   // read();
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        stack<char> st;
        string s1;
        bool flag=true;
        char d;
        if(i==1)
            scanf("%c",&d);
        getline(cin,s1);

        for(int j=0;j<s1.size();j++)
        {

            if(s1[j]=='(' || s1[j]=='[')
            {


                st.push(s1[j]);
            }
            else if(st.size()==0)
            {
                flag=false;
                break;
            }
            else if((st.size()>0 && st.top()=='(' && s1[j]==')' ) || (st.size()>0 && st.top()=='[' && s1[j]==']'))
            {

                st.pop();
            }

            else
            {
               // test(3);
                flag=false;

                break;
            }
          //  cout<<j<<endl;

        }
        if(st.size()==0 && flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}


