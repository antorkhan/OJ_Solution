#include<bits/stdc++.h>
#define read() freopen("input.txt","r",stdin)
using namespace std;

int main()
{
   // read();
    int i;
    while(scanf("%d",&i) && i!=0)
    {
        int ans=0;
        vector<int> str;
        int l=log2(i)+1;
        for(int p=0;p<l;p++)
        {
            int bit=i&1;
            str.push_back(bit);

            if(bit==1)
                ans++;
            i=i>>1;
        }
     //   reverse(str.begin(),str.end());

        cout<<"The parity of ";
        for(int j=str.size()-1;j>=0;j--) cout<<str[j];
        cout<<" is "<<ans<<" (mod 2).\n";


    }
}
