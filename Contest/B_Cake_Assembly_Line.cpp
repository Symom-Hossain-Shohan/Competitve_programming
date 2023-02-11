#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mx = 1e5+5; 
ll a[mx], b[mx];
ll n, w, h; 

ll good(ll x)
{
    ll tmp[n] ; 
    tmp[0] = x; 
    for(int i=1;i<n;i++) tmp[i] = tmp[i-1] + b[i]-b[i-1];
    
    for(int i=0;i<n;i++)
    {
        if(tmp[i]<a[i]-w) return 3; 
        else if(tmp[i]+2*h>a[i]+w) return 2; 
    }
    return 1; 
}

void solve()
{
    cin >> n >> w >> h; 
    
    for(int i =0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    ll l = a[0]-w, r = a[0]+w; 

    while(l<=r)
    {
        ll mid = (l+r)/2; 

        ll ans = good(mid);
        if(ans==1) 
        {
            cout << "YES\n";
            return; 
        }
        else if(ans==2)
        {
            r = mid-1; 
        }
        else l = mid+1; 

    }

    cout << "NO\n";


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