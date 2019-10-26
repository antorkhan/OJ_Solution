#include<bits/stdc++.h>
using namespace std;
vector<int> Set;


void getSubSet( vector<int> subSet, int index)
{
    if( index == Set.size())
    {
        cout<<"[";
        for( int i=0; i<subSet.size(); i++)
        {
            cout << subSet[i];
            if( i<subSet.size()-1)
            {
                cout<< ',';
            }
        }
        cout<<"] \n";
    }
    if(index >= Set.size())
        return;
    if( index < Set.size())
    {
        getSubSet(subSet, index+1);
        subSet.push_back(Set[index]);
        getSubSet(subSet, index+1);
    }
}

int main()
{
//    freopen("input.txt","r",stdin);
    int test_case;
    cin>>test_case;
    for(int test = 0; test< test_case; test++)
    {
        int n;
        cin >> n;
        Set.clear();
        for(int i=0; i<n; i++)
        {
            int temp;
            cin>> temp;
            Set.push_back(temp);
        }
        vector<int> subSet;
        getSubSet(subSet,0);
    }
}
