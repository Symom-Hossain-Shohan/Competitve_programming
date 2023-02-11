#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7; 

ll bigmod(ll b,ll n)
{
    if(n==0) return 1; 
    else if(n%2==0)
    {
        ll res = bigmod(b, n/2); 
        return ((res%mod) * (res%mod))%mod; 
    }
    else 
    {
        return (b*bigmod(b, n-1)) %  mod; 
    }
}

void solve()
{
    ll n, m, k; 
    cin >> n >> m >> k; 
    if(k==-1 and n%2!=m%2) cout << 0 << endl; 
    else 
    {
        ll ans = bigmod(2, n-1);
        //cout << ans << ' ';
        ans = bigmod(ans, m-1); 
        cout << ans << endl; 
    }
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