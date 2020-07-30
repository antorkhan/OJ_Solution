#include<bits/stdc++.h>
using namespace std;

int main()
{
    bool is_prime[1000009];
    vector<int> primes;
    memset(is_prime, true, sizeof(is_prime));
    for(int i=2; i<= (int)sqrt(1000009); i++)
    {
        int j = i*i;
        if(is_prime[i] == true)
        {
            while(j <= 1000009)
            {
                is_prime[j] = false;
                j += i;
            }
        }


    }
    is_prime[1] = false;
    for(int i = 2; i<= 1000009; i++)
    {
        if(is_prime[i])
        {
            primes.push_back(i);

        }
    }

    //cout << primes[low1 - primes.begin()- 1];
    int n;
    while(cin >> n)
    {
        if(n ==0)
            return 0;
        vector<int>::iterator low_bound = lower_bound(primes.begin(), primes.end(), n);
        int prime_index = low_bound - primes.begin()- 1;
        // n == a + n
        int a = primes[prime_index];
        int b = n - a;
        while( n  != a + b || !is_prime[b] )
        {
            a = primes[--prime_index];
            b = n - a;

        };
        cout << n <<" = " << b << " + "<< a << endl;
    }

    //cout << primes.size();
}
