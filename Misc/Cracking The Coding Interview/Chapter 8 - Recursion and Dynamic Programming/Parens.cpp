#include<bits/stdc++.h>

using namespace std;


string balance(int oa, int ca, string prev)
{
//    cout<<oa<<" "<<ca<<" "<<prev<<endl;
    string ret = "";
    if( oa == 0 && ca == 0)
    {
        return prev + ", ";
    }
    if( oa > 0)
    {
        ret += balance( oa-1, ca +1, prev+"(");
    }
    if( ca > 0 )
    {
        ret += balance( oa, ca -1, prev+")");
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    cout<< balance(n,0,"");
}
