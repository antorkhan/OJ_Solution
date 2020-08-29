#include<bits/stdc++.h>
using namespace std;
string CACHE[5010];
string add_string(string s1, string s2){
    int len_dif = s1.length()- s2.length();

    string str_padding = "";
    for(int i =0; i< abs(len_dif); i++){
        str_padding += '0';
    }
    if(len_dif > 0){
        s2 = str_padding + s2;
    }
    else{
        s1 = str_padding + s1;
    }
    int carry = 0;
    string ret = "";

    for(int i=s1.length()-1; i>=0; i--){
        int d1 = s1[i] - '0';
        int d2 = s2[i] - '0';
        ret += (char)((d1+d2+carry)%10 + '0');
        carry = (int)(d1+d2+carry)/10;
    }
    if(carry > 0) {
        ret =  ret + (char)(carry + '0');
    }

    reverse(ret.begin(), ret.end());
    return ret;
}
string fib(int n){
    if(CACHE[n][0] != '*') return CACHE[n];
    else{
        CACHE[n] =add_string(fib(n-1),fib(n-2));
        return CACHE[n] ;
    }

}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    for(int i =0;i<5010;i++ ) CACHE[i] = "*";
    CACHE[0] = "0";
    CACHE[1] = "1";
    int n;
    while(cin >> n)
        cout << "The Fibonacci number for "<< n <<" is "<< fib(n)<<endl;
}
