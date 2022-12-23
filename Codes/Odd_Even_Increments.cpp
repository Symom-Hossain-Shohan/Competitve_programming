#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n) ;
    for(int i=0 ; i< n;i++) cin >> v[i] ; 
    bool ok=true ; 
    for(int i=0;i<n;i+=2) 
    {
        if(v[i]%2!=v[0]%2) ok=false ; 
    }

    for(int i=1; i<n; i+=2) 
    {
        if(v[i]%2!=v[1]%2) ok=false ; 
    }

    if(ok) cout << "YES\n" ; 
    else cout << "NO\n" ;
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