#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n ; 
    ll l = 1, r = n ;
    while(r>l+1)
    {
        ll m = (l+r)/2 ; 
        ll x; 
        cout << "? " << l << ' ' << m << endl; 
        cin >> x ;
        if(x<n-1)
        {
            l = m ;
        }
        else if(x==n-1)
        {
            r=m ; 
        }
        else 
        {

        }
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