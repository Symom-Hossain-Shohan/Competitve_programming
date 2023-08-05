#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,m, c; 
vector<ll> adj[2001];
map<ll,ll> mp; 
ll memo[2001][1005]; 

ll dp(ll pos, ll T)
{
    if(T> 1000)
    {
        if(pos==1) return 0; 
        else return -1e18; 
    }

    ll &ans = memo[pos][T];

    if(ans==-1)
    {
        ll res; 
        if(pos==1)
        {   
            res = 0; 
        }
        else res = -1e18; 

        for(auto child: adj[pos])
        {
            res = max(res, mp[pos] + dp(child, T+1) + c*(T-1)*(T-1) - c*(T*T)); 
        }
        ans = res; 
    }

    return ans; 
}

void solve()
{
    cin >> n >> m >> c; 
    for(int i=1;i<=n; i++) 
    {
        ll x; 
        cin >> x; 
        mp[i] = x;  
    }

    for(int i=0;i<m; i++){
        ll u, v; 
        cin >> u >> v; 
        adj[u].push_back(v);
    }

    memset(memo, -1, sizeof(memo)); 

    cout << dp(1, 1) << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}