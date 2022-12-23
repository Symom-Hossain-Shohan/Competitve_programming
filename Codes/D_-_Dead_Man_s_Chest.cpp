#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n; 
    vector<ll> v(n) ;
    for(auto &i: v) cin >> i ;
    sort(v.begin(),v.end()) ;
    bool ok=true ; 
    for(int i=0;i<n;i++) 
    {
        if(v[i]%v[0]!=0) ok=false ; 
    }

    if(ok)
    {
        ll t = v[n-1]/v[0] ;
        t = n-t; 
        if(t%2==0) cout << "Davy Jones\n";
        else cout << "Jack Sparrow\n";
    }
    else 
    {
        ll t = v[n-1] ;
        t = n-t ;
        if(t%2==0) cout << "Davy Jones\n";
        else cout << "Jack Sparrow\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}