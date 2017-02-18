#include <bits/stdc++.h>

using namespace std;

#define sq(x) ((x) * (x))
#define read() freopen("input.txt", "r", stdin)
#define ll64 long long

int main()
{
    //read();
    for(; ;){
        ll64 N;
        scanf("%lld", &N);
        if(N == 0) break;
        for(ll64 i = 1; ; i++){
            if(sq(i) >= N){
                ll64 rem = sq(i) - N;
                ll64 diff = sq(i) - sq(i - 1);
                int r, c;
                if(rem > diff / 2){
                    r = i;
                    c = diff - rem;
                }
                else{
                    r = rem + 1;
                    c = i;
                }
                if(i % 2 == 0) swap(r, c);
                printf("%d %d\n", r, c);
                break;
            }
        }
    }
}
