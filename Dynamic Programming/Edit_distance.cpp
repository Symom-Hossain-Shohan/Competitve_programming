//https://www.spoj.com/problems/EDIST/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll memo[2001][2001];
string a, b; 

ll dp(ll i, ll j)
{
    if(i==a.size()) return b.size()-j; 
    if(j==b.size()) return a.size()-i; 

    ll &ans = memo[i][j];

    if(ans == -1)
    {
        if(a[i]==b[j])
        {
            ans = min({dp(i+1, j+1), 1+dp(i, j+1), 1+dp(i+1, j), 1+dp(i+1, j+1)});
        }
        else 
        {
            ans = min({1+dp(i, j+1), 1+dp(i+1, j), 1+dp(i+1, j+1)}); 
        }
    }
    return ans; 
}

void solve()
{
    memset(memo, -1, sizeof(memo));
    cin >> a >> b; 

    cout << dp(0, 0) << endl; 

    
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