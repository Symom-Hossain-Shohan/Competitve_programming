#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n; 
    vector<ll> a(n), b(n);
    for(auto &i: a) cin >> i;
    for(auto &i: b) cin >> i; 

    ll om = 0, andy = 0; 
    ll cnt = 0;
    for(int i=0;i<n; i++)
    {
        if(a[i]) cnt++; 
        else 
        {
            om = max(om, cnt);
            cnt = 0; 
        }
    }

    om = max(om, cnt);
    cnt = 0; 
    for(int i=0;i<n; i++)
    {
        if(b[i]) cnt++; 
        else 
        {
            andy = max(cnt, andy);
            cnt = 0; 
        }
    }

    andy = max(andy, cnt);
    if(andy == om) cout << "Draw\n"; 
    else if(andy> om) cout << "Addy\n";
    else cout << "Om\n"; 
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