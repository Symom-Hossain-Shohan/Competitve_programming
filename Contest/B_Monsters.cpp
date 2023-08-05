#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(pair<ll,ll> a, pair<ll,ll> b)
{
    if(a.first==b.first) return a.second<b.second; 
    else return a.first>b.first; 
}

void solve()
{
    ll n, k; 
    cin >> n >> k; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    vector<pair<ll,ll>> vp; 
    vector<ll> ans; 
    for(int i=0;i<n;i++)
    {
        ll x = v[i]%k; 
        if(x==0) ans.push_back(i+1); 
        else vp.push_back({x, i+1}); 
    }
    sort(vp.begin(), vp.end(), cmp); 
    if(!ans.empty()) for(auto i: ans) cout << i << ' '; 
    for(auto i: vp) cout << i.second << ' '; 
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