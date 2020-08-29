#include<stdio.h>
#include<iostream>
#include <cmath>
using namespace std;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    unsigned long long n,r;
    while(cin >> n >> r)
    {
        //cout << n << r << endl;
        long double digit = 0;
        for(unsigned long long i=n-r+1;i<=n; i++)
            digit += log10((double)i);
        for(unsigned long long i=1;i<=r; i++)
            digit -= log10((double)i);
        printf ("%d\n", int(round(digit))+1);
    }
    return 0;
}

