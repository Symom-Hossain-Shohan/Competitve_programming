#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    // same similar
    ll ss_op = 0;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            ss_op++;

    ll rev_op = 0;
    for (int i = 0; i < n; i++)
        if (a[i] != b[n - i - 1])
            rev_op++;

    ll ans = 1e18;
    // same calculation

    
    if (ss_op % 2)
    {
        ans = min(ans, 2 * ss_op - 1);
    }
    else
        ans = min(ans, 2 * ss_op);

    // rev

    if (rev_op % 2)
        ans = min(ans, 2 * rev_op);
    else
        ans = min(ans, 2 * rev_op - 1);

    if (a == b)
        ans = 0;
    else
    {
        reverse(a.begin(), a.end());
        if (a == b)
            ans = 2;
    }

    cout << ans << endl;
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