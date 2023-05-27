#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    ll pos = 0, neg = 0; 
    for(int i = 1;i<=n; i++)
    {
        ll x; 
        cin >>x; 
        if(x==1) pos += i; 
        else neg += i; 
    }

    cout << abs(pos-neg) << endl; 
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