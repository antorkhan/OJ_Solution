#include<iostream>
#include <math.h>
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int seat_num=2*m;
    int seat_pos=k;
    int lane_pos=1;
    while(1)
    {
        if(seat_pos-seat_num>0)
        {
            seat_pos=seat_pos-seat_num;
            lane_pos++;

        }
        else
        {
            break;
        }
    }

    double t=seat_pos;
    int desk_pos=ceil(t/2);
    cout<<lane_pos<<" "<<desk_pos;
    if(seat_pos%2==0)
        cout<<" R";
    else
        cout<<" L";





}
