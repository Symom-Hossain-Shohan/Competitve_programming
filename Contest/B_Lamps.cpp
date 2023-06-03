#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<vector<ll>> v(n+1, vector<ll> ()); 

    for(int i=1;i<=n; i++)
    {
        ll a, b; 
        cin >> a >> b; 
        v[a].push_back(b);
    }

    ll ans = 0; 
    for(int i=1;i<=n; i++)
    {
        if(!v[i].empty())
        {
            sort(v[i].rbegin(), v[i].rend()); 
            for(int j=0;j<min(i, (int)v[i].size());j++) ans += v[i][j];
        }
    }
    cout << ans << endl; 
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