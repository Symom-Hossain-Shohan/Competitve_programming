#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, a, b ; 
    cin >> n >> a >> b ;
    vector<ll> v(n) ; 
    for(auto &i : v)  cin >> i ;
    
    ll ans = v[0]*b ; 
    ll cap = 0 ; 
    for(int i=1 ; i<n ; i++)
    {
        ll x = (v[i]-cap)*b ; 
        ll y = (v[i-1]-cap)*a + (v[i]-v[i-1])*b ; 
        if(y<=x)
        {
            cap = v[i-1] ; 
        }  
        ans += min(x, y) ; 
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