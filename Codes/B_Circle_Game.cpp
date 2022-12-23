#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n ;
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    if(n%2==1) cout << "Mike\n"; 
    else 
    {
        ll mn = 1e18; 
        ll ix = -1; 
        for(int i=0;i<n;i++)
        {
            if(v[i]<mn)
            {
                mn = v[i]; 
                ix = i; 
            }
        }
        if(ix%2==0) cout << "Joe\n"; 
        else cout << "Mike\n"; 
    }
     
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