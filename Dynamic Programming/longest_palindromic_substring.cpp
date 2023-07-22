#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll memo[1005][1005]; 
string str; 

ll dp(ll i, ll j)
{
    if(i>=j) return 1; 
    if(memo[i][j]!=-1) return memo[i][j];

    if(str[i]==str[j]) return memo[i][j] = dp(i+1, j-1);
    else return memo[i][j] = 0; 
}

void solve()
{
    cin >> str; 
    memset(memo, -1, sizeof(memo)); 

    int ans = 0; 
    for(int i=0;i<(int)str.size(); i++)
    {
        for(int j=i; j<(int)str.size(); j++)
        {
            if(dp(i, j)) ans = max(ans, j-i+1); 
        }
    }

    cout << ans << endl; 
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