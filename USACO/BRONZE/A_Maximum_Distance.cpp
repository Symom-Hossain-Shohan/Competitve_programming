#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<pair<ll,ll>> vp(n);
    for(auto &i: vp) cin >> i.first; 
    for(auto &i: vp) cin >> i.second; 

    ll dmax = -1; 
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ll x= vp[i].first - vp[j].first; 
            ll y = vp[i].second - vp[j].second; 
            dmax = max(dmax, x*x + y*y);
        }
    }
    cout << dmax << endl; 
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