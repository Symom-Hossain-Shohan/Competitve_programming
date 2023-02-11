#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m, k; 
    cin >> n >> m >> k; 
    vector<ll> v(m);
    for(auto &i: v) cin >> i; 
    sort(v.rbegin(), v.rend());

    for(int i = 1;i<=m;i++)
    {
        if((v[i-1]-1)*k+i>n) 
        {
            cout << "NO\n";
            return; 
        }
    }
    cout << "YES\n";
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