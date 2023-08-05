#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n; 
vector<string> v(1001); 
ll memo[1001][1001];
const ll mod = 1e9 + 7; 
ll dp(ll i, ll j)
{
    if(i==n-1 and j==n-1 and v[i][j]=='.')
    {
        return 1; 
    }
    if(i>n or j>n) return 0; 
    if(memo[i][j] !=-1) return memo[i][j];

    if(v[i][j]=='*') return 0; 
    else 
    {
        return memo[i][j] = (dp(i+1, j) + dp(i, j+1)) % mod; 
    }
}

void solve()
{
    cin >> n; 
    for(int i=0;i<n;i++) cin >> v[i];
    memset(memo, -1, sizeof(memo)); 
    cout << dp(0, 0) << endl; 
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