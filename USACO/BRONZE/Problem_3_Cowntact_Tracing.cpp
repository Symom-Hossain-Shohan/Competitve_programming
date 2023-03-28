#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k; 
    cin >> n >> k; 
    string s; 
    cin >> s; 
    vector<pair<ll,pair<ll,ll>>> v(k); 
    for(int i=0;i<k;i++)
    {
        cin >> v[i].first >> v[i].second.first >> v[i].second.second; 
    }
    
    sort(v.begin(), v.end()); 
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