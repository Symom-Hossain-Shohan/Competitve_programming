#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll r, c; 
    ll x1, y1, x2, y2; 
    cin >> r >> c; 
    cin >> x1 >> y1 >> x2 >> y2; 
    ll ans1 = 0, ans2 = 0; 
    if(x1-1>=1) ans1++; 
    if(x1+1<=r) ans1++; 
    if(y1-1>=1) ans1++; 
    if(y1+1<=c) ans1++; 

    if(x2-1>=1) ans2++; 
    if(x2+1<=r) ans2++; 
    if(y2-1>=1) ans2++; 
    if(y2+1<=c) ans2++; 
    cout << min(ans1, ans2) << endl; 
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