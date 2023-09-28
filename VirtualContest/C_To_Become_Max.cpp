#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k;
vector<ll> v;

bool is_good(ll H)
{

    for (int i = 0; i < n; i++)
    {
        ll cost = 0;
        bool ok = false;
        ll x = H;
        for (int j = i; j < n and !ok; j++)
        {
            if (v[j] >= x)
            {
                ok = true;
                // break;
            }
            else
                cost += x - v[j], x--;
        }
        if (ok and cost <= k)
            return true;
    }
    return false;
}

void solve()
{
    cin >> n >> k;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    ll low = *max_element(v.begin(), v.end()), high = *max_element(v.begin(), v.end()) + k, ans = low;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        if (is_good(mid))
        {
            ans = mid, low = mid + 1;
        }
        else
            high = mid - 1;
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