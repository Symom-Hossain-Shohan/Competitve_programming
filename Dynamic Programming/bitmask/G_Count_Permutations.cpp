#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k; 
ll memo[(1<<15)+1][16];

ll dp(ll mask, ll prev)
{
    if(mask == (1<<n) - 1) return 1; 

    ll &ans = memo[mask][prev]; 
    if(ans == -1)
    {
        ans = 0; 
        for(int i=0;i<n;i++)
        {
            if(!(mask & (1<<i)) && (prev==0 or abs(prev-(i+1))<=k))
            {
                ans += dp(mask | (1<<i), i+1);
            }
        }
    }
    return ans; 
}

void solve()
{
    cin >> n >> k; 
    memset(memo, -1, sizeof(memo)); 

    cout << dp(0, 0) << endl; 
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