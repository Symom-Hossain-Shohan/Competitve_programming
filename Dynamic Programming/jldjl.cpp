#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k; 
ll memo[401][401];
ll ar[401];


ll dp(ll pos, ll op)
{
    if(op>k+1) return 1e18; 
    if(pos==n) return 0; 

    if(memo[pos][op]!=-1) return memo[pos][op];
    ll ans = 1e18, curmax = 0; 
    for(int i=pos; i<n ;i++)
    {
        curmax = max(curmax, ar[i]); 

        ans = min(ans, dp(i+1, op+1) + curmax * (i-pos+1)); 
    }
    return memo[pos][op] = ans; 
}

void solve()
{
    cin >> n >> k;
    ll sum = 0; 
    for(int i=0; i<n;i ++) cin >> ar[i], sum += ar[i];
    memset(memo, -1, sizeof(memo));

    cout << dp(0, 0)-sum  << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}