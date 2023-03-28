#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> mark(n + 1, -1), visited(n + 1, -1), v(m);
    for (auto &i : v)
        cin >> i;
    for (int i = 0; i < k; i++)
    {
        ll cow, pos;
        cin >> cow >> pos;
        mark[cow] = pos;
        visited[pos] = cow;
    }

    if (count(v.begin(), v.end(), 1) == 0)
    {
        for (int i = m - 1; i >= 0; i--)
        {
            if (mark[v[i]] == -1)
            {
                if (i == m - 1)
                {
                    ll j = n;
                    while (visited[j] != -1)
                        j--;
                    visited[j] = v[i];
                    mark[v[i]] = j;
                }
                else
                {
                    ll j = mark[v[i + 1]];
                    while (visited[j] != -1)
                        j--;
                    visited[j] = v[i];
                    mark[v[i]] = j;
                }
            }
        }

        if (mark[1] != -1)
        {
            cout << mark[1] << endl;
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == -1)
            {
                cout << i << endl;
                return;
            }
        }
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            if (mark[v[i]] == -1)
            {
                if (i == 0)
                {
                    ll j = 1;
                    while (visited[j] != -1)
                        j++;
                    mark[v[i]] = j;
                    visited[j] = v[i];
                }
                else
                {
                    ll j = mark[v[i - 1]];
                    while (visited[j] != -1)
                        j++;
                    mark[v[i]] = j;
                    visited[j] = v[i];
                }
            }
        }

        if (mark[1] != -1)
        {
            cout << mark[1] << endl;
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == -1)
            {
                cout << i << endl;
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    ll tc = 1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}