#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;
ll common[17][17];
vector<pair<ll, ll>> vp;
ll memo[(1<<16)+1]; 

ll dp(ll mask)
{
    if(mask == (1<<n)-1) return 0; 
    if(memo[mask]!=-1) return memo[mask]; 

    ll ans = 1e18; 

    for(int i = 0;i<n;i++)
    {
        if(!(mask & (1<<i)))
        {
            ll m1 = mask | (1<<i);
            for(int j=0;j<n;j++)
            {
                if(vp[i].first == vp[j].first) m1 = m1 | (1<<j); 
            }
            ans = min(ans, 1 + dp(m1)); 

            m1 = mask | (1<<i);
            for(int j=0;j<n;j++)
            {
                if(vp[i].second == vp[j].second) m1 = m1 | (1<<j); 
            }

            ans = min(ans, 1 + dp(m1)); 
            m1 = mask | (1<<i); 
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                ans = min(ans, 1 + dp(m1 | common[i][j])); 
            }
        }
    }
    return memo[mask] = ans;
}

void solve()
{
    cin >> n;
    vp.resize(n);
    for (auto &i : vp)
        cin >> i.first >> i.second;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            ll m1 = 0 | (1 << i) | (1 << j);
            for (int k = 0; k < n; k++)
            {
                if (i == k or j == k)
                    continue;
                if ((vp[i].second - vp[j].second) * (vp[i].first - vp[k].first) == (vp[i].second - vp[k].second) * (vp[i].first - vp[j].first))
                {
                    m1 = m1 | (1 << k);
                }
            }
            common[i][j] = m1; 
        }
    }
    memset(memo, -1,sizeof(memo)); 
    cout << dp(0) << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}