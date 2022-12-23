#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll x, ar[4];
    cin >>  x;
    cin >> ar[1] >> ar[2] >> ar[3];
    ll cnt = 0;
    while (ar[x] != 0)
    {
        cnt++;
        x = ar[x];
    }
    if (cnt == 2) cout << "YES\n";
    else cout << "NO\n";
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