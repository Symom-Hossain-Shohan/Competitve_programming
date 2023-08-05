#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll b, c, h; 
    cin >> b >> c >> h; 
    ll x = 0, y = 0; 
    if(c+h>=b-1) x = b + (b-1);
    if(c+h+1<=b) y = (c+h+1) + c+ h; 
    cout << max(x, y) << endl; 
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