#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string s;

ll memo[32][32][2][2];

ll dp(ll cnt, ll pos, ll last, ll prev)
{
    if (pos == (int)s.size())
    {
        return cnt;
    }

    if (memo[cnt][pos][last][prev] != -1)
        return memo[cnt][pos][last][prev];

    ll till = last ? (s[pos] - '0') : 1;
    ll x = 0;
    for (int i = 0; i <= till; i++)
    {
        x += dp(cnt + (i == 1 && prev == 1), pos + 1, last && (i == till), i);
    }

    return memo[cnt][pos][last][prev] = x;
}

void solve()
{
    ll n;
    cin >> n;
    s.clear();
    while (n)
    {
        s += to_string(n % 2);
        n /= 2;
    }

    reverse(s.begin(), s.end());
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 0, 1, 0) << endl;
    // cout << s << endl;
    // dp("", 0, 1, 0);
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