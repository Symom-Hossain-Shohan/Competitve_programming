#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s; 
    cin >> s; 
    s = "#" + s; 
    int n = s.length();
    vector<ll> suffix(n+2, 0), prefix(n+2, 0);

    for(int i=1;i<=n;i++)
    {
        if(s[i]=='1') prefix[i]++;
        prefix[i] += prefix[i-1]; 
    }

    for(int i=n;i>=1;i--)
    {
        if(s[i]=='0') suffix[i]++; 
        suffix[i] += suffix[i+1];
    }

    ll ans = 1e18; 
    for(int i=1;i<=n;i++)
    {
        ll res = 0; 
        if(s[i]=='1' and s[i+1]=='0')
        {
            res = 1e12 + (prefix[i]-1+ suffix[i+1]-1) * (1e12+1);
        }
        else res = (prefix[i] + suffix[i+1]) * (1e12+1);

        ans = min(ans, res);

        if(s[i]=='0' and s[i-1]=='1')
        {
            res = 1e12 + ((prefix[i-1]-1+suffix[i]-1)*(1e12+1)); 
        }
        else res = (prefix[i-1]+suffix[i])*(1e12+1);

        ans = min(ans, res);
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