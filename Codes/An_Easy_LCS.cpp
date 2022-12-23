#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string a, b; 
    cin >> a >> b; 
    int n = (int)a.size(), m = (int)b.size(); 

    string dp[n+1][m+1]; 

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 or j==0) dp[i][j] = ""; 
            else if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1] + a[i-1]; 
            else if(dp[i-1][j].size()>dp[i][j-1].size()) dp[i][j] = dp[i-1][j]; 
            else if(dp[i-1][j].size()<dp[i][j-1].size()) dp[i][j] = dp[i][j-1]; 
            else if(dp[i-1][j]<dp[i][j-1]) dp[i][j] = dp[i-1][j]; 
            else dp[i][j] = dp[i][j-1]; 
        }
    }
    if(dp[n][m].size()==0) cout << ":(\n"; 
    else cout << dp[n][m] << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        cout << "Case " << t << ": " ; 
        solve();
    }
    return 0;
}