#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n; 
vector<pair<ll,ll>> vp; 

ll memo[(1<<16)]; 

ll dp(ll mask)
{
    if(mask == (1<<n)-1) return 0; 

    ll ans = 1e18; 
    if(memo[mask]!=-1)
    {
        return memo[mask]; 
    }
    for(int i=0;i<n;i++)
    {
        if(!(mask & (1<<i)))
        {
            //case1 x = a
            ll m1 = mask | (1<<i);
            for(int j=0;j<n;j++)
            {
                if(vp[i].first == vp[j].first) m1 = m1 | (1<<j); 
            }
            ans = min(ans, 1 + dp(m1)); 

            //case2 y = b
            m1 = mask | (1<<i);
            for(int j=0;j<n;j++)
            {
                if(vp[i].second == vp[j].second) m1 = m1 | (1<<j); 
            }
            ans = min(ans, 1 + dp(m1)); 

            //case3 slope equal 
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;

                m1 = mask | (1<<i) | (1<<j);
                for(int k=0;k<n;k++)
                {
                    if(i==k or j==k) continue;
                    if((vp[i].second-vp[j].second)*(vp[i].first - vp[k].first) == (vp[i].second- vp[k].second)*(vp[i].first-vp[j].first))
                    {
                        m1 = m1 | (1<<k);
                    }
                }
                ans = min(ans, 1 + dp(m1)); 
            }

        }
    }
    return memo[mask] = ans; 
}

void solve()
{
    cin >> n; 
    vp.resize(n);
    for(auto &i: vp)
    {
        cin >> i.first >> i.second; 
    }
    memset (memo, -1, sizeof(memo)); 

    cout << dp(0) << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": ";
        
        solve();
    }
    return 0;
}