#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, B, x, y ;
    cin >> n >> B >> x >> y; 
    vector<ll> v; 
    v.push_back(0); 
    for(int i=1;i<=n;i++)
    {
        if(v[i-1]+x<=B) v.push_back(v[i-1]+x);
        else v.push_back(v[i-1]-y);
    }

    ll ans  = 0 ;
    for(auto i: v) ans+= i ;
    //cout << endl;  
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