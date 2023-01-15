#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    ll x = v[0];
    for(int i = 1;i<n;i++) x ^= v[i];
    x = v[0] ^  x; 
    v[0] ^= x; 
    v[1] ^= x; 
    for(int i=1;i<n-1;i++)
    {
        x = v[0] ^ v[i];
        v[i] = v[i] ^ x; 
        v[i+1] = v[i+1] ^ x; 
    } 
    sort(v.begin(), v.end()); 
    if(v[0]==v.back()) cout << "YES\n";
    else cout << "NO\n"; 
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