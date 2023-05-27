#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
bool cmp(pair<ll,ll> a, pair<ll,ll> b)
{
    if(a.first==b.first) return a.second > b.second; 
    else return a.first<b.first; 
}

void solve()
{
    ll n; 
    cin >> n; 
    vector<pair<ll,ll>> vp; 
    for(int i=0;i<n;i++)
    {
        ll x, y; 
        cin >> x >> y; 
        vp.push_back({x-y, x+y}); 
    }
    sort(vp.begin(), vp.end(), cmp); 
    ll y = vp[0].second; 
    ll cnt = 1; 
    for(int i = 1;i<n;i++)
    {
        if(vp[i].second>y) 
        {
            cnt++; 
            y = vp[i].second; 
        }
    }

    cout << cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}