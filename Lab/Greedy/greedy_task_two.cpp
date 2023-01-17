#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<pair<ll,ll>> vp(n);
    for(int i=0;i<n;i++)
    {
        ll x, y; 
        cin >> x >> y; 
        vp[i].second = x; 
        vp[i].first = y; 
    }

    sort(vp.begin(), vp.end()); 
    //for(auto i: vp) cout << i.first << ' ' << i.second << endl; 


    ll x = vp[0].first, cnt = 1; 
    for(int i=1;i<n;i++)
    {
        if(vp[i].second>=x)
        {
            cnt ++; 
            x = vp[i].first; 
            //cout << i << endl; 
            
        }
    }
    cout << cnt << " jobs can be done.\n";
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