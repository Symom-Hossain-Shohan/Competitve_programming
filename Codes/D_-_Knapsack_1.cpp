#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, w; 

vector<pair<ll,ll>> v; 

ll sum[101][100005]; 

ll dp(ll pos, ll weight)
{
    if(pos == n) return 0 ;
    if(sum[pos][weight]!= -1) return sum[pos][weight]; 

    if(v[pos].first<=weight)
    {
        ll val1 = v[pos].second + dp(pos+1, weight-v[pos].first); 
        ll val2 = dp(pos+1, weight); 

        return sum[pos][weight] = max(val1, val2); 
    }
    else return sum[pos][weight] = dp(pos+1, weight); 
}

void solve()
{
    cin >> n >> w ; 
    v.resize(n); 
    memset(sum, -1, sizeof sum); 
    for(int i = 0; i< n; i++) cin >> v[i].first >> v[i].second ; 

    cout << dp(0, w) << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}