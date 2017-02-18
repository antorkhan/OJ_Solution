#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;

int main()
{

    int n;
    string s1;
    while(1)
    {
        cin>>n;
        if(n==0) return 0;
        cin>>s1;
        int len=s1.length();
        int be=0;
        n=len/n;
        while(be<=len)
        {
            string sub= s1.substr(be,n);
            reverse(sub.begin(),sub.end());
            cout<<sub;
            be=be+n;

        }
        cout<<"\n";



    }
}
