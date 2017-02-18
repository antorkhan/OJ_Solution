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

using namespace std;
int main()
{
    string s;
    map<string,int> m;
    vector<string> v;
    stack<string> st;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;

        st.push(s);


    }
    while(!st.empty())
    {
        s=st.top();
        st.pop();
        if(m[s]!= 1)
        {
            m[s]=1;
            v.push_back(s);

        }
    }
    int l=v.size();
    for(int i=0;i< l;i++)
    {
        cout<<v[i]<<endl;
    }
}


