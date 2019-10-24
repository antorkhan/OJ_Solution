#include<bits/stdc++.h>

using namespace std;



int multiply_helper(int smaller, int bigger)
{
    if( smaller == 0)
        return 0;
    else if (smaller == 1)
        return bigger;

    int first_half_smaller = smaller >> 1;
    int result_first_half  = multiply_helper( first_half_smaller, bigger );
    int result_second_half = smaller & 1 ? multiply_helper( smaller - first_half_smaller, bigger ) : result_first_half;
    return result_first_half + result_second_half;
}
int multiply(int a, int b)
{
    int smaller = a > b? b : a;
    int bigger = a > b? a : b;
    multiply_helper(smaller,bigger);
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<< multiply(a,b);
}
