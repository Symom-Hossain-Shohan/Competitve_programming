#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n; 
ll x[17], y[17], cmn[17][17], memo[(1<<16)+1];


bool good(ll i, ll j, ll k)
{
    return (y[i]-y[j])*(x[j]-x[k]) == (y[j]-y[k])*(x[i]-x[j]); 
}


ll dp(ll mask)
{
    if(mask == (1<<n) - 1) return 0; 
    ll &ans = memo[mask];
    if(ans !=-1) return ans; 

    ll cnt = __builtin_popcount(mask); 
    if(cnt==n-1 or cnt == n-2) return 1; 
    ans = 1e18; 
    for(int i = 0;i<n;i++)
    {
        if(!(mask & (1<<i)))
        {
            for(int j = i+1;j<n;j++)
            {
                if(!(mask & (1<<j)))
                {
                    ans = min(ans, 1 + dp(mask | cmn[i][j])); 
                }
            }
            break;
        }
       
    }
    return ans; 
}

void solve()
{
    cin >> n; 
    for(int i=0;i<n;i++) cin >> x[i] >> y[i]; 

    memset(memo, -1, sizeof(memo)); 
    memset(cmn, 0, sizeof(cmn)); 

    for(int i=0;i<n;i++)
    {
        for(int j=i+1; j<n;j++)
        {
            ll mask = 0 | (1<<i) | (1<<j); 
            for(int k= j+1;k<n; k++)
            {
                if(good(i, j, k)) mask = mask | (1<<k); 
            }
            cmn[i][j] = cmn[j][i] = mask; 
        }
    }
    cout << dp(0) << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " <<t << ": "; 
        solve();
    }
    return 0;
}