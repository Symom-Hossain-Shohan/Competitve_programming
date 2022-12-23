#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s, t; 
    cin >> s >> t; 
    int n, m; 
    n = s.size(); 
    m = t.size(); 

    int dp[n+1][m+1]={0}; 
    for(int i= 0;i<=n;i++)
    {
        for(int j =0 ;j<=m;j++)
        {
            if(i==0 or j==0) dp[i][j] = 0; 
            else if(s[i-1]==t[j-1]) dp[i][j] = 1+ dp[i-1][j-1]; 
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]); 
        }
    }

    string lcs; 
    int i = n, j= m; 
    while(i>0 and j>=0)
    {
        if(s[i-1]==t[j-1]) lcs.push_back(s[i-1]), i--, j--; 
        else if(dp[i-1][j]>dp[i][j-1]) i--; 
        else j--; 
    }
    reverse(lcs.begin(), lcs.end()); 
    cout << lcs << endl; 
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