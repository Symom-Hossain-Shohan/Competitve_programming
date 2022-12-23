#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n , k ;
    cin >> n >> k ; 
    vector<ll> v(31,0) ; 
    
    for(int i=0 ; i<n;i++)
    {
        ll x ; 
        cin >> x ; 
        for(int j= 30;j>=0; j--)
        {
            if(x & (1<<j)) v[j]++;
        }
    }
    ll ans = 0 ; 
    for(int j = 30; j>=0;j--)
    {
        int need = n - v[j] ; 
        if(need<=k)
        {
            k-=need ; 
            ans+= 1<<j ; 
        }
    }
    cout << ans << endl ;
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