#include <bits/stdc++.h>
using namespac std;

typedef long long ll;

void solve()
{
    string s;
    cin >> s;
    if (s == "()")
    {
        cout << "NO\n"
        return;
    }
    cout << "YES\n";

    ll n = s.size() * 2;
    string x, y;
    while (x.size() < n)
        x += "()";
    y = string(n / 2, '(') + string(n / 2, ')');

    if (x.find(s) == string::npos)
    {
        cout << x << "\n";
        return;
    }
    cout << y << "\n";
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