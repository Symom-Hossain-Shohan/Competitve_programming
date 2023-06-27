#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m; 
    cin >> n >> m; 
    vector<pair<ll,ll>> range(m);
    for(auto &i: range) cin >> i.first >> i.second;  

    ll k; 
    cin >> k; 
    vector<ll> q(k);
    for(auto &i: q) cin >> i; 

    ll l = 0, r = k - 1; 

    ll ans = -1; 

    while(l<=r)
    {
        ll mid = (l+r)/2; 
        ll ar[n+1] = {0}; 

        for(int i=0;i<=mid; i++)
        {
            ar[q[i]] = 1; 
        }

        for(int i=1;i<=n; i++) ar[i] += ar[i-1]; 

        bool good = false; 

        for(int i=0;i<m;i++)
        {
            ll left = range[i].first, right = range[i].second; 

            ll ones = ar[right] - ar[left-1]; 
            ll zeros = right-left + 1 - ones; 

            if(ones>zeros) 
            {
                good = true; 
                break;
            }
        }

        if(good) 
        {
            ans = mid+1; 
            r = mid - 1; 
        }
        else l = mid+1; 
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