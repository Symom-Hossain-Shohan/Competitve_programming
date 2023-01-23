#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<vector<ll>> dp(n, vector<ll>(n, 0)); 
    
    for(int j=0;j<n;j++) cin >> dp[0][j];  
    for(int i=1;i<n;i++)
    {
        for(int j =0;j<n-i;j++)
        {
            dp[i][j] = dp[i-1][j] ^ dp[i-1][j+1]; 
        }
    }

    for(int i=1;i<n;i++)
    {
        for(int j = 0;j<n-i;j++)
        {
            dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i-1][j+1]}); 
        }
    }

    ll q; 
    cin >> q; 
    while(q--)
    {
        ll l, r; 
        cin >> l >> r; 
        //l--, r--; 
        l--; 
        cout << dp[r-l-1][l] << endl; 
    }
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