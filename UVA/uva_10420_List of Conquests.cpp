#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
#include<limits.h>
#define MAX 10000
#define LLI long long int
#define INT_VEC vector<int>
#define read() freopen("input.txt","r",stdin)

using namespace std;
int main()
{
    read();
    int t;
    cin>>t;
    vector<string> v;
    map<string,int> m;
    int K;
    for( K=0;K<t;K++)
    {

        string s,t;
        cin>>s;

        if(m[s]!= 0)
        {
            m[s]++;
        }
        else
        {
            m[s]=1;
            v.push_back(s);
        }
        getline(cin,t);

    }
    sort(v.begin(),v.end());
     for(int i=0;i<v.size();i++)
     {

        cout<<v[i]<<" "<<m[v[i]]<<endl;
     }




}


