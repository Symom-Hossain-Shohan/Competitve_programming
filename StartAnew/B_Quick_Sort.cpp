// https://codeforces.com/contest/1768/problem/B
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;

    map<ll, ll> mp;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        mp[x] = i;
    }
    ll cnt = 1;
    for (int i = 2; i <= n; i++)
    {
        if (mp[i] > mp[i - 1])
            cnt++;
        else
            break;
    }
    cnt = n - cnt;
    cout << cnt / k + (cnt % k != 0) << endl;
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