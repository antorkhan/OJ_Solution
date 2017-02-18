#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;


unsigned long long int getDecimal(vector<int> V)
{

    unsigned long long int multiplier=1,result=0;
    int size=V.size();
    reverse(V.begin(),V.end());
    for(int i=0;i<V.size();i++)
    {
       if(V[i]==1)
       {
           result+=multiplier;
           multiplier=multiplier*2;
       }
       else
         multiplier=multiplier*2;
    }
    return result;

}
vector<int> return_gray(vector<int> trial)
{
    vector<int> grey;
    int len=trial.size();
    grey.push_back(trial[0]);
    for(int i=0 ;i<len-1 ; i++)
    {
        if((trial[i]==0 && trial[i+1]==0) || (trial[i]==1 && trial[i+1]==1) )
        {
            grey.push_back(0);
        }
        else
        {
            grey.push_back(1);
        }
    }
    return grey;

}
int main()
{
  //  freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    while(n--)
    {
        vector<int> myVec;
        unsigned long long int bit,decimal,grey=0;
        cin>>bit>>decimal;
        int last_bit;
        for(int i=1;i<=bit;i++)
        {
            int last_bit=decimal&1;
            decimal=decimal>>1;
            myVec.push_back(last_bit);
        }
        int len=myVec.size();
        reverse(myVec.begin(),myVec.end());
//        for(int i=0;i<len;i++)
//        {
//            cout<<myVec[i];
//        }
//        cout<<endl;
        vector<int> gray= return_gray(myVec);

        unsigned long long int ans=getDecimal(gray);
        cout<<ans<<endl;
    }
}
