#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    if(n==1) 
    {
        ll x; 
        cin >> x; 
        cout << 0 << endl; 
    }
    else 
    {
        vector<ll> v(n);
        for(auto &i: v) cin >> i; 
        vector<ll> g; 
        for(int i=0;i<n/2; i++)
        {
            g.push_back(abs(v[i]-v[n-i-1])); 
        }

        ll gcd = g[0];
        for(auto i: g) gcd = __gcd(gcd, i); 
        cout << gcd << endl; 
    }
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