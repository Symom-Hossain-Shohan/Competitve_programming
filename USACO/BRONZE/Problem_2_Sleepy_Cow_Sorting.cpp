#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    ll cnt = 1, ix = n-2; 
    while(v[ix]<v[ix+1]) cnt++, ix--; 
    cout << n-cnt << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}