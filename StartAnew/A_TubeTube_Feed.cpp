#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, t; 
    cin >> n >> t; 
    vector<ll> a(n), b(n);
    for(auto &i: a) cin >> i; 
    for(auto &i: b) cin >> i; 

    ll ans = -1, ix=-1; 
    for(int i =0;i<n ;i++)
    {
        if(i+a[i]<=t)
        {
            if(b[i]>ans)
            {
                ans = b[i];

                ix = i+1; 
            }
        }
    }

    cout << ix << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}