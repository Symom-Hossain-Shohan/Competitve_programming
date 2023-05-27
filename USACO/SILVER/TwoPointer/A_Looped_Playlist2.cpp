#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    unsigned long long n, k, l = 0, otv = 1e18 + 1, sa;
    long long p, c, sum = 0, x = 0;
    cin >> n >> p;
    vector<long long> a(n * 2);
    for (int i = 0; i < n; i++)
        cin >> sa, a[i] = sa, a[i + n] = sa, sum += sa;
    a[n] = a[0];
    c = (p / sum) * n;
    p %= sum;
    for (int r = 0; r < n * 2; r++)
    {
        x += a[r];
        while (x - a[l] >= p)
        {
            x -= a[l];
            l++;
        }
        if (x >= p)
            if (otv > r - l + 1)
                otv = r - l + 1, k = l;
    }
    cout << k % n + 1 << " " << otv + c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}