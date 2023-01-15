#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, q; 
    cin >> n >> q; 
    vector<ll> v(n+1, 0);
    while(q--)
    {
        ll l, r, k; 
        cin >> l >> r >> k; 
        l--; 
        v[l] += k; 
        v[r] -= k; 
    }
    for(int i=1;i<=n;i++) v[i] +=v[i-1];

    ll mx = v[0];
    for(int i=1;i<n;i++) mx = max(mx, v[i]);

    cout << mx << endl; 
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