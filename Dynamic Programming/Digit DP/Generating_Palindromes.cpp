#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string s; 
ll memo[101][101]; 

ll dp(ll i, ll j)
{
    if(i>j) return 0; 
    if(memo[i][j]!=-1) return memo[i][j]; 

    if(s[i]==s[j])
    {
        return memo[i][j] = dp(i+1, j-1); 
    }
    else 
    {
        return memo[i][j] = min(1 + dp(i+1, j), 1 + dp(i, j-1)); 
    }
}

void solve()
{
    cin >> s; 
    memset(memo, -1, sizeof(memo)); 

    cout << dp(0, (int)s.size()-1) << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": "; 
        solve();
    }
    return 0;
}