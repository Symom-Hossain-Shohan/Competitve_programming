#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll r, c; 
int t[101], d[101], crood[101];
ll n; 



map<tuple<ll,ll,ll>, ll> mp; 


ll dp(ll row, ll col, ll tt)
{
    if(tt>2e4+500) return 1e18; 
    if(row==r and col==c) return 0; 

    if(row==r and col!=c) return 1e18; 
    if(col==c and row!=r) return 1e18; 

    for(int i=0;i<n ;i++)
    {
        if(t[i]==tt and ((d[i]==1 and row==crood[i] ) or(d[i]==2 and col == crood[i])))  return 1e18; 
    }

    ll ans = min({1 + dp(row+1, col, tt+1), 1+dp(row, col+1, tt+1), 1 + dp(row, col, tt+1) });

    return mp[{row, col, tt}] = ans;  

}

void solve()
{
    cin >> r >> c; 
    cin >> n; 
    for(int i = 0;i<n; i++) cin >> t[i] >> d[i] >> crood[i]; 
    mp.clear();

    if(dp(0, 0, 0)>=1e18) cout << -1 << endl; 
    else cout << dp(0, 0, 0) << endl; 
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