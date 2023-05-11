#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n); 
    unordered_map<ll,vector<ll>> mp; 
    for(auto &i: a) cin >> i; 
    for(auto &i: b) cin >> i; 

    for(int i=0;i<n; i++) mp[a[i]].push_back(b[i]);
    set<ll> st(a.begin(), a.end()); 
    
    for(auto i: st)
    {
        sort(mp[i].rbegin(), mp[i].rend()); 

        for(int j=1; j<(int)mp[i].size(); j++)
        {
            mp[i][j] += mp[i][j-1]; 
        }
    }

    vector<ll> ans(n+1);
    for(auto u: st)
    {
        ll sz = mp[u].size();
        for(int i=1;i<=sz; i++)
        {
            ll x = sz % i; 
            ans[i] += mp[u][sz-x-1];
        }
    }

    for(int i=1;i<=n; i++) cout << ans[i] << ' ';
    cout << endl; 

    
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