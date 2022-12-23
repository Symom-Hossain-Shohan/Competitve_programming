#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> ans;
    if (n % 2 == 0)
    {
        for (int i = 1, j = n; i < j; i++, j--)
        {
            ans.push_back(j);
            ans.push_back(i);
        }
    }
    else
    {
        for (int i = 1, j = n; i <= n / 2; i++, j--)
        {
            ans.push_back(j);
            ans.push_back(i);
        }
        ans.push_back(n / 2 + 1);
    }
    for (auto i : ans)
        cout << i << ' ';
    cout << endl;
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