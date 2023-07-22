#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n);

    for(auto &i: v) cin >> i; 
    if(n==1)
    {
        cout << 1 << endl; 
    }
    else if(count(v.begin(), v.end(), 0)==n)
    {
        cout << n << endl; 
    }
    else 
    {
        ll cnt = 0; 
        ll ans = v[0]; 
        for(int i = 1;i<n ;i++)
        {
            if(ans==0)
            {
                cnt++; 
                ans = v[i];
            }
            else 
            {
                ans = ans & v[i];
            }
        }
        if(ans==0) cnt++; 
        if(cnt) 
        {
            cout << cnt << endl; 
        }
        else cout <<  1 << endl; 
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