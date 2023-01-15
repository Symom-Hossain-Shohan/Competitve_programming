#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll x, y; 
    cin >>x >> y; 
    if(x*y-x-y<=0) cout << 1000*x*y - x - y << endl; 
    else cout << x*y-x - y <<endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}