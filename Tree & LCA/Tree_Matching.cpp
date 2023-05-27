#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 1; 
ll memo[N][2];

vector<ll> adj[N];

ll dp(ll cur, bool included, ll par)
{
    if(memo[cur][included]!=-1) return memo[cur][included];

    if(included)
    {
        ll preCalc = 0; 
        for(auto child: adj[cur])
        {
            if(child != par)
            {
                preCalc += dp(child, 1, cur);
            }
        }

        ll ans = 0; 
        for(auto child: adj[cur])
        {
            if(child != par)
            {
                ans = max(ans, preCalc - dp(child, 1, cur) + 1 + dp(child, 0, cur)); 
            }
        }
        return memo[cur][included] = ans; 
    }
    else 
    {
        ll ans = 0; 
        for(auto child: adj[cur])
        {
            if(child != par)
                ans += max(dp(child, 0, cur), dp(child, 1, cur));
        }
        return memo[cur][included] = ans; 
    }
}

void solve()
{
    ll n; 
    cin >> n; 
    for(int i = 1;i<n; i++)
    {
        ll u, v; 
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(memo, -1, sizeof(memo));

    cout << max(dp(1, 0, -1), dp(1, 1, -1));
    
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