#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ncr[1001][1001];
const ll mod = 1e9; 

ll dp(ll n, ll r)
{
    if(n<r) return 0; 
    else if(r == 1) return n; 
    else if(r == 0 or r == n) return 1; 
    ll &ans = ncr[n][r]; 
    if(ans == -1) 
    {
        ans = (dp(n-1, r-1) +  dp(n-1, r))% mod; 
    } 
    return ans % mod; 
}

void solve()
{
    ll n; 
    cin >> n; 
    for(int i = 0;i<=n;i++) 
    {
        cout << dp(n, i)%mod << ' '; 
    }
    cout << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    memset(ncr, -1, sizeof(ncr)); 
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}