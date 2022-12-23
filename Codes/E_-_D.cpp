#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll k, x; 
ll calc(ll m)
{
    if(m<=k) 
    {
        return m*(m+1)/2 ;
    }
    else 
    {
        ll v = k*(k+1)/2; 
        m = m - k; 
        v += (k-1)*k/2; 
        m = k - m -1; 
        v -= m*(m+1)/2; 
        return v; 
    }
    
}

bool good(ll m)
{
    if(calc(m)>=x) return true; 
    else return false; 
}

void solve()
{
    cin >> k >> x; 
    ll  l = 1, r = 2*k-1; 
     
    ll ans  =2*k-1; 
    while(l<=r)
    {
        ll mid = (l+r)/2; 
        if(good(mid))
        {
            ans = mid; 
            r = mid - 1; 
        }
        else l = mid+1; 
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