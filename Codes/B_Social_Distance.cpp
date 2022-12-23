#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m; 
    cin >> n >> m ;
    vector<ll > v(n) ;
    for(auto &i: v) cin >> i; 
    sort(v.rbegin(),v.rend()) ;
    ll ans = v[0] ;
    for(int i=0;i<n-1;i++) ans+=v[i] ;
    if(ans+n<=m) cout << "YES\n";
    else cout << "NO\n";
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