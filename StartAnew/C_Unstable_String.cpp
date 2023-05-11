#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
string s; 

void solve()
{
    cin >> s; 
    ll n = s.length();
    ll dp[n+1][2];

    dp[0][0] = dp[0][1] = 0; 
    ll ans = 0; 
    for(int i=1;i<=n; i++)
    {
        if(s[i-1]=='?')
        {
            dp[i][0] = 1LL + dp[i-1][1];
            dp[i][1] = 1LL + dp[i-1][0];
        }
        else if(s[i-1]=='0')
        {
            dp[i][0] = 1LL + dp[i-1][1];
            dp[i][1] = 0; 
        }
        else 
        {
            dp[i][1] = 1LL + dp[i-1][0];
            dp[i][0] = 0; 
        }
        ans += max(dp[i][0], dp[i][1]); 
    }
    cout << ans << endl;
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