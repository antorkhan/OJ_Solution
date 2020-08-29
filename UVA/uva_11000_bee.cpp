#include<bits/stdc++.h>
using namespace std;
string CACHE[5010];
string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);
    string str = "";

    int n1 = str1.length(), n2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());

    return str;
}
string fib(int n){
    if(CACHE[n][0] != '*') return CACHE[n];
    else{
        CACHE[n] =findSum(findSum(fib(n-1),fib(n-2)),"1");
        return CACHE[n] ;
    }

}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    for(int i =0;i<5010;i++ ) CACHE[i] = "*";
    CACHE[0] = "1";
    CACHE[1] = "2";
    int n;
    while(cin >> n)
    {
        if(n==-1) return 0;
        else if(n==0)
            cout<< 0<<" "<<1<<endl;
        else
            cout<< fib(n-1)<<" "<<fib(n)<<endl;
    }
}
