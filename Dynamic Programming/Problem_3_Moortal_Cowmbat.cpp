#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m, k;
ll mat[26][26];
string s;

ll dp(ll pos, ll prev, ll op)
{
    if(pos==n) return 0; 

    if(op==0)
    {
        ll val1 = 1e18; 
        for(int i=0;i<m; i++) val1 = min(val1, mat[s[pos]-'a'][i] + dp(pos+1, i, k-1)); 
        ll val2 = mat[s[pos]-'a'][prev] + dp(pos+1, prev, 0); 
        return min(val1, val2);
    }
    else 
    {
        ll val2 = mat[s[pos]-'a'][prev] + dp(pos+1, prev, op-1);
        return val2; 
    }
}

void solve()
{
    cin >> n >> m >> k >> s;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    for (int k = 0; k < m; k++)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
    ll ans = 1e18; 

    for(int i=0;i<m; i++) ans = min(ans, dp(0, i, k)); 

    cout << ans << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}