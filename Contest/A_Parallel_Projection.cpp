#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll x, y, z; 
    ll a, b, c, d; 
    cin>> x >> y >> z >> a >> b >> c >> d; 
    ll v1 = 0, v2, v3, v4; 
    v1 = b + z + abs(c-a) + d; 
    v2 = y-b + z + abs(c-a) + y-d; 
    v3 = a + z + abs(d-b) + c; 
    v4 = x-a + z + abs(d-b) + x-c; 
    cout << min({v1, v2, v3,v4}) << endl; 
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