#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll a, b; 
    cin >> a >> b; 
    ll k = 1e5 + 1; 
    ll ans = 1e18; 
    for(int i = 1;i<=k; i++)
    {
        ans = min(ans, (a+i-1)/i + (b+i-1)/i + i-1); 
    }
    cout << ans << endl; 
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