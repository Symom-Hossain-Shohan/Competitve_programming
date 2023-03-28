#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m; 
    
vector<pair<ll,ll>> vp, vpy;

bool cmp(pair<ll,ll> a, pair<ll,ll> b)
{
    return a.second < b.second ; 
}

ll fun(ll x, ll y)
{
    ll first = 0, second = 0 , third = 0, fourth = 0; 
    for(int i=0;i<n;i++)
    {
        if(vp[i].first>x and vp[i].second>y) first++; 
        else if(vp[i].first<x and vp[i].second>y) second++; 
        else if(vp[i].first<x and vp[i].second<y) third++; 
        else fourth++; 
    }
    return max({first, second, third, fourth}); 
}

void solve()
{
     cin >> n >> m; 
    vp.resize(n);
    for(auto &i: vp) cin >> i.first >> i.second; 
    sort(vp.begin(), vp.end()); 
    
    vpy = vp; 
    sort(vpy.begin(), vpy.end(), cmp); 

    ll ans = 1e18; 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ll x = vp[i].first+1, y = vpy[j].second+1; 
            ans = min(ans, fun(x, y));
        }
    }
    cout << ans << endl; 


    //case2  n/2+1


}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}