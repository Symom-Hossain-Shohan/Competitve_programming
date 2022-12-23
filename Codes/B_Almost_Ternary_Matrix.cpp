#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll x, y;
    cin >> x >> y;
    y /= 2;
    string one = "", two = "";
    for (int i = 0; i < y; i++)
    {
        if (i % 2 == 0)
            one += "1 0 ";
        else
            one += "0 1 ";
    }
    for (int i = 0; i < y; i++)
    {
        if (i % 2 == 1)
            two += "1 0 ";
        else
            two += "0 1 ";
    }
    x /= 2;
    for (int i = 0; i < x; i++)
    {
        if (i % 2 == 0)
        {
            cout << one << endl
                 << two << endl;
        }
        else
            cout << two << endl
                 << one << endl;
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