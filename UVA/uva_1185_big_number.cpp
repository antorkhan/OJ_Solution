#include<bits/stdc++.h>
using namespace std;
int CACHE[10000001];
int main(){
    memset(CACHE,0, sizeof(CACHE));
    double total = 0;
    for(int i=1;i<=10000001;i++){
        total+= log10(i);
        CACHE[i] = (int)total + 1;
    }
    int N;
    cin >>N;
    for( int i=1; i<=N; i++){
        int x;
        scanf("%d",&x);
        printf("%d\n",CACHE[x]);
    }
    return 0;
}
