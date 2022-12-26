//https://codeforces.com/problemset/problem/264/B
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> v[100001];

void solve()
{
    ll n;
    cin >> n; 
    ll ar[n], dp[n];

    for(int i=0;i<n;i++)
    {
        cin >> ar[i];

        for(ll j=2;j*j<=ar[i]; j++)
        {
            if(ar[i]%j==0)
            {
                v[i].push_back(j);
                while(ar[i]%j==0) ar[i]/=j; 
            }
        }

        if(ar[i]!=1) v[i].push_back(ar[i]);
    }

    map<ll,ll> mp; 

    for(auto i: v[0]) mp[i] = 1; 
    ll ans = 1; 
    for(int i=1;i<n;i++)
    {
        ll mx = -1; 
        for(auto i: v[i]) mx = max(mx, mp[i]);
        for(auto i: v[i]) mp[i] = mx+1; 
        dp[i] = mx +1; 
        ans = max(ans, dp[i]);
    }

    cout << ans <<endl; 
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