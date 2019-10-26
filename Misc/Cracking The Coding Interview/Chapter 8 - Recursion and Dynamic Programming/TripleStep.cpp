#include<bits/stdc++.h>
using namespace std;

long long answer = 0;
long long cache[10010];
void n_steps(int total_steps, int available_steps)
{
//    cout<< cache[available_steps];
    if(cache[available_steps] == -1)
    {
//        cout << "boom\n";
        if(available_steps == 0) // Zero Available
        {
            answer++;
            cache[available_steps] = answer;
        }

        else if(available_steps > 0)
        {
            n_steps(total_steps, available_steps - 3);
            n_steps(total_steps, available_steps - 2);
            n_steps(total_steps, available_steps - 1);
        }


    }
    else
    {
        answer += cache[available_steps];
    }
    return;


}

int main()
{

    int steps =35;
//    cin >> steps;
    memset(cache,-1, sizeof cache);
    n_steps(steps,steps);
    cout<< answer;
}
