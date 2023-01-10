#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, w, k; 
vector<ll> y; 
ll memo[105][105];

ll dp(ll pos, ll move )
{
    if(pos== n or move == 0) return 0; 
    if(memo[pos][move] !=-1) return memo[pos][move];

    //include current position
    ll p = upper_bound(y.begin(), y.end(), y[pos]+w) - (y.begin());

    ll v = p- pos + dp(p, move-1);
    //exclude current position

    ll v1 = dp(pos+1, move);

    return memo[pos][move] =  max(v, v1);
}

void solve()
{
    cin >> n >> w  >> k; 
    y.resize(n);
    for(int i = 0; i< n;i++) cin >> y[i] >> y[i];

    sort(y.begin(), y.end()); 
    memset(memo, -1, sizeof(memo));

    cout << dp(0, k ) << endl; 
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