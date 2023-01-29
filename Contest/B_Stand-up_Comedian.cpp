#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll a, b, c, d; 
    cin >> a >> b >> c >> d; 
    if(a==0)
    {
        cout << 1 << endl; 
        return; 
    }
    ll ans = a + 2*(min(b, c)) + min(a+1, abs(c-b)+d); 
    cout << ans << endl; 
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