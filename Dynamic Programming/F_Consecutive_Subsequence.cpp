//https://codeforces.com/problemset/problem/977/F
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n; 
    ll ar[n], dp[n];;
    for(int i=0;i<n;i++)
    {
        cin >> ar[i];
        dp[i] = 1;  
    }
    map<ll,ll> mp; 
    mp[ar[0]] = 1; 
    ll ans = 1, ix = 0; 
    for(int i=1;i<n;i++)
    {
        dp[i] = max(dp[i], mp[ar[i]-1] + 1); 
        mp[ar[i]] = dp[i]; 
        if(ans<dp[i]) ans = dp[i], ix = i;  
    }

    vector<ll> v; 
    v.push_back(ix); 
    ans--; 
    ll x = ar[ix] - 1; 
    for(int i=ix-1;i>=0 and ans; i--)
    {
        if(ar[i]==x)
        {
            ans--; 
            v.push_back(i);
            x--; 
        }
    }

    reverse(v.begin(), v.end()); 
    cout << v.size() << endl; 
    for(auto i: v) cout << i + 1 << ' ';
    
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