#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n);

    ll sum = 0; 
    for(auto &i: v) cin >> i, sum += i; 
    bool ok = false; 
    for(int i = 0;i<n-1;i++)
    {
        if(v[i]==-1 and v[i+1]==-1) ok = true; 
    }

    if(ok) cout <<  sum + 4 << endl; 
    else 
    {
        if(count(v.begin(), v.end(), -1)) cout << sum << endl; 
        else cout << sum - 4 << endl; 
    }
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