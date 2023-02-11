#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll memo[500004][28];

string s; 
ll n, m; 

ll dp(ll pos, ll prv)
{
    if(pos==s.size()) return 0; 

    ll &ans = memo[pos][prv];
    if(ans == -1)
    {
        ll res = 1e18; 
        for(int i = 1;i<=m;i++)
        {
            if(i==prv) continue;
            char c = 'A' + i-1; 
            if(c!=s[pos]) res = min(res, 1 + dp(pos+1, i)); 
            else res = min(res, dp(pos+1, i));
        }
        ans = res;
    }

    return ans; 
}


void solve()
{
    
    cin >> n >> m; 
    memset(memo, -1, sizeof(memo));
    cin >> s; 
    cout << dp(0, 27) << endl;  
    

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