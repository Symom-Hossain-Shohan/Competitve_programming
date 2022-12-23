#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n ;
    vector<ll> v(n+1); 
    for(int i = 1; i <= n; i++) cin >> v[i]; 
    vector<ll> ans(n+1); 
    //for(auto i: ans) cout << i << ' '; 
    ll t  = n; 
    for(int i = n ; i>=1 ;i--)
    {
        ll x = max(1ll, i-v[i]) ; 
        if(x<i)
        {
            ans[x] -= 1; 
            ans[i] += 1; 
        }
    }

    for(int i= 1 ;i<=n ;i++) ans[i] += ans[i-1]; 
    ll cnt = 0 ; 
    for(int i=1;i<=n;i++) if(ans[i]>=0) cnt++; 
    cout << cnt << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for(ll t = 1;t <= tc; t++)
    {
        solve();
    }
    return 0;
}