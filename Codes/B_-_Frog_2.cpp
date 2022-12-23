#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> h; 
ll n, k; 
ll cost[100005]; 

ll dp(ll pos)
{
    if(pos==0) return 0; 

    if(pos<=k) return abs(h[pos]-h[0]); 

    if(cost[pos]!=-1) return cost[pos]; 
    
    ll val = 1e18 ; 
    for(ll i = 1; i<=k; i++)
    {
        val = min(val, dp(pos-i)+ abs(h[pos]- h[pos-i])); 
    }

    return cost[pos] = val; 

}


void solve()
{
   //cin >> n, k; 
    cin >> n >> k; 
    h.resize(n); 
    memset(cost, -1, sizeof cost); 
    for(auto &i: h) cin >> i; 

    cout << dp(n-1) << endl; 
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