#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    ll sum = 0, neg = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        sum += abs(x);
        neg += (x < 0);
    }

    ll gcd = __gcd(sum, (n - neg));
    if (n - neg == 0)
        cout << "inf" << endl;
    else
        cout << sum / gcd << "/" << (n - neg) / gcd << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}