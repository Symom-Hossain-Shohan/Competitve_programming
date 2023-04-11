#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string num;

ll memo[9][2][91];

ll good(ll x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return 0;
    }
    if (x == 1)
        return 0;
    else
        return 1;
}

ll dp(ll pos, bool last, ll sum)
{
    if (pos == num.length())
    {
        return good(sum);
    }

    
    ll till = last ? (num[pos] - '0') : 9;
    ll ans = 0;
    if(memo[pos][last][sum] !=-1) return memo[pos][last][sum];
    for (int i = 0; i <= till; i++)
    {
        ans += dp(pos + 1, last && (i == till), sum + i);
    }

    return memo[pos][last][sum] = ans;
}

ll fun(ll n)
{
    num = to_string(n);
    memset(memo, -1, sizeof(memo));
    return dp(0, true, 0);
}

void solve()
{
    ll l, r;
    cin >> l >> r;
    cout << fun(r) - fun(l - 1) << endl;
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