#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    if (n % 2)
    {
        for (int i = 1; i <= n; i++)
            cout << i << ' ';
        cout << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
            cout << 2 * i << ' ';
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}