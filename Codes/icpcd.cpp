#include<bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;

void solve()
{
    ll r, q; 
    cin >> r >> q; 
    vector<ll> mat[r+1];  
    for(int i=1;i<=r;i++)
    {
        ll n; 
        cin >> n; 
        while(n--)
        {
            ll x; 
            cin >> x; 
            mat[i].push_back(x); 
        }
    }
    //cin >> q ;
    while(q--)
    {
        ll i, j; 
        cin >> i >> j; 
        cout << mat[i][j-1] << endl; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for(ll t = 1;t <= tc; t++)
    {
        solve();
    }
    return 0;
}