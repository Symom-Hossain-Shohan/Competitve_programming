#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n); 
    ll sum = 0; 
    for(auto &i: v) cin >> i, sum += i; 
    if(n==1) cout << "NO\n"; 
    else 
    {
        ll res = 0; 
        for(int i = 0;i<n; i++)
        {
            if(v[i]==1) res--; 
            else res += (v[i]-1); 
        } 
        if(res>=0) cout << "YES\n"; 
        else cout << "NO\n"; 
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