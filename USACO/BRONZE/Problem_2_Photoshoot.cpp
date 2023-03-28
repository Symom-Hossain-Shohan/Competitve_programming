#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n; 
    vector<ll> a, b; 
    for(int i=0;i<n-1;i++) 
    {
        ll x; 
        cin >> x; 
        b.push_back(x);
    }

    for(int i=1;i<=n;i++) a.push_back(i);

    do
    {
        /* code */
        bool ok = true; 
        for(int i=0;i<n-1;i++)
        {
            if(b[i]!=a[i] + a[i+1]) ok = false; 
        }
        if(ok)
        {
            cout << a[0] ; 
            for(int i=1;i<n;i++) cout << ' ' << a[i];
            return; 
        }
    } while (next_permutation(a.begin(), a.end()));
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}