#include<bits/stdc++.h>
using namespace std;

long long big_mod(int b, int p, int m)
{
    if( p==0)
        return 1;
    else if(p&1)
    {
        return ((b%m)*(big_mod(b, p-1, m)))%m;
    }
    else
    {
        return (big_mod(b,p/2,m))*(big_mod(b,p/2,m))%m;
    }
}


int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    char char_input;
    string bin_input="";
    string raw_input;
    while(getline(cin, raw_input))
    {
//        cout << raw_input << endl;
        for(int i = 0; i<raw_input.length(); i++)
        {
            if(raw_input[i] == '1' || raw_input[i]=='0')
            {
                bin_input += raw_input[i];
            }
            else if(raw_input[i] == '#')
            {

//                cout <<"***********************"<<endl;
//                cout << bin_input<<endl;
//                cout <<"***********************"<<endl;
                int answer = 0;
                for(int j= 0; j<bin_input.length(); j++)
                {
                    if( ((int) bin_input[j] - '0') ==1 )
                        answer = (answer + big_mod(2,bin_input.length()-j-1,131071))%131071;

                }
                answer == 0 ? cout << "YES\n" : cout << "NO\n";
                bin_input = "";
            }
        }


    }
}
