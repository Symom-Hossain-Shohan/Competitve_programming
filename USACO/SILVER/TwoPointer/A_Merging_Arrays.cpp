#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m; 
    cin >> n >> m; 
    vector<ll> a(n), b(m), c(n+m);
    for(auto &i: a) cin >> i; 
    for(auto &i: b) cin >> i; 

    ll i = 0, j = 0, k = 0; 
    while(i<(int)a.size() and j<(int)b.size())
    {
        if(a[i]<=b[j]) 
        {
            c[k] = a[i]; i++, k++; 
        }
        else 
        {
            c[k] = b[j]; j++, k++; 
        }
    }

    while(i<(int)a.size())
    {
        c[k] = a[i];
        i++, k++; 
    }
    while(j<(int)b.size())
    {
        c[k] = b[j];
        k++, j++; 
    }

    for(auto l: c) cout << l << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}