#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll x = 2, y = 5; 
    for(int i=0;i<3;i++)
    {
        if((x&(1<<i)) and (y&(1<<i))==0)
        {
            y = y | (1<<i);
            x = x & (~(1<<i));
            cout << i << ' ';
        }
    }

    cout << x << ' ' << y <<endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}