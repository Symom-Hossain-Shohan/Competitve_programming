#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
map<ll, ll> dig = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}};

void solve()
{
    ll k;
    cin >> k;
    vector<ll> ans;
    while (k)
    {
        ans.push_back(dig[k % 9]);
        k /= 9;
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i;
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