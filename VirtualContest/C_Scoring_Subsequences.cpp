#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    ll cnt = 1; 
    cout << 1 << ' '; 
    for(int i=1;i<n; i++)
    {
        if(v[i-cnt]>=(cnt+1)) cnt++; 
        cout << cnt << ' '; 
    }

    cout << endl; 
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