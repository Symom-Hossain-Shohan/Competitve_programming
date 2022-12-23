#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, q; 
    cin >> n >> q ; 
    vector<ll> c(n) ; 
    for(auto &i: c) cin >> i ; 
    sort(c.rbegin(),c.rend()) ; 

    for(int i = 1;i<n;i++) c[i]+=c[i-1] ; 
    while(q--)
    {
        ll x ;
        cin >> x ;
        if(x>c[n-1]) cout << - 1<< endl; 
        else if(c[0]>=x) cout << 1 << endl; 
        else 
        {
            int l =0, r= n-1 ; 
            while(r>l+1)
            {
                int mid = (l+r)/2 ; 
                if(c[mid]>=x) r = mid; 
                else l =mid ; 
            }
            cout << r+1 << endl ;
        }
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