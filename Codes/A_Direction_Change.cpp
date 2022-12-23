#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m ;
    cin >> n >> m ;
    if(n<m) swap(n,m) ;
    ll ans= 2*(m-1) ;
    ll x = (n-m) ;
    ans+= x ;
    if(x%2) x-- ;
    ans+= x ;
    if(m==1 and n>2) cout << -1 << endl ; 
    else cout << ans << endl;
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