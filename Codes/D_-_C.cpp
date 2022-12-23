#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, e; 
vector<ll> v; 

bool fun(ll mid)
{
    ll p = v[0], q = e-1; 
    for(int i = 1;i<n;i++)
    {
        if(v[i]-p>=mid)
        {
            q--; 
            p = v[i]; 
        }
    }
    
     
    if(q<=0) return true; 
    else return false; 
}

void solve()
{
    cin >> n >> e; 
    v.resize(n); 
    for(auto &i: v) cin >> i; 
    sort(v.begin(), v.end()); 

    ll l = 0, r = v[n-1]+1; 
    ll ans = -1; 
    while(l<=r)
    {
        ll mid = (l+r)/2; 

        if(fun(mid))
        {
            ans = mid; 
            l = mid+1; 
        }
        else r = mid - 1; 
    }
    cout << ans << endl; 
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