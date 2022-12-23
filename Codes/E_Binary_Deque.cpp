#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k; 
vector<ll> v; 

bool good(ll mid)
{
    for(int i=1;i<=n-mid+1; i++)
    {
        if(v[i+mid-1]-v[i-1]<=k) return true;
    }
    return false; 
}

void solve()
{
    cin >> n >> k; 
    v.assign(n+1, 0); 
    for(int i=1;i<=n;i++) cin >> v[i]; 

    for(int i=1;i<=n;i++) v[i] += v[i-1]; 
    if(v[n]<k) cout << -1 << endl ;
    else 
    {
        ll l = 0, r = n; 
        ll ans = -1; 
        while(l<=r)
        {
            ll mid = (l+r)/2; 
            if(good(mid)) 
            {
                ans = mid; 
                l = mid+1;
            } 
            else r = mid - 1; 
        }
        cout << n - ans << endl; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}