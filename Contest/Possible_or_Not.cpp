#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, b;
    cin >> n >> b;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    unordered_set<int> unq(a.begin(), a.end());
    vector<int> c;

    for (int x : unq)
    {
        if ((x & b) == b)
        {
            c.push_back(x);
        }
    }

    if (c.empty())
    {
        cout << "NO" << endl;
    }
    else
    {
        int x = c[0];
        for (int i = 1; i < c.size(); i++)
        {
            x = x & c[i];
        }

        if (x == b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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