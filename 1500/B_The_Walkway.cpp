#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> v(m + 2);
    for (int i = 1; i <= m; i++)
        cin >> v[i];
    v[0] = 1 - d;
    v[m + 1] = n + 1;
    ll sum = 0;
    for (int i = 1; i <= m + 1; i++)
    {
        sum += max(0ll, (v[i] - v[i - 1] - 1)) / d;
    }

    map<ll, ll> freq;
    ll ans = 1e9;
    for (int i = 1; i <= m; i++)
    {
        ll tmp = sum+m;
        tmp -= (v[i] - v[i - 1] - 1) / d;
        tmp -= (v[i + 1] - v[i] - 1) / d;
        tmp += (v[i + 1] - v[i - 1] - 1) / d;
        tmp--;
        ans = min(ans, tmp);
        freq[tmp]++;
    }

    cout << ans << ' ' << freq[ans] << endl;
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