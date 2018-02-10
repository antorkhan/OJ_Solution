#include<bits/stdc++.h>
#define read() freopen("input.txt","r",stdin)
#define write() freopen("output.txt","w",stdout)
using namespace std;

int main()
{

    read();write();
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        string inp;
        char dummy;
        if(tc==1)
            scanf("%c",&dummy);
        getline(cin,inp);
        vector<int> memory(100,0);
        int ptr=0;
        for(int i=0;i<inp.size();i++)
        {
            if(inp[i]=='>')
            {
                ptr=(ptr+1)%100;
            }
            else if(inp[i]=='<')
            {
                ptr=(ptr+99)%100;
            }
            else if(inp[i]=='+')
            {
                memory[ptr]=(memory[ptr]+1)%256;
            }
            else if(inp[i]=='-')
            {
                memory[ptr]=(memory[ptr]+255)%256;
            }

        }
        printf("Case %d: ",tc);
        for(int i=0;i<memory.size();i++)
        {

            cout<<hex<<uppercase<<setfill('0') << setw(2) <<memory[i];
            if(i==99)
                cout<<'\n';
            else
                cout<<' ';
        }

    }
}
