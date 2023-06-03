#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k, szOne, szTwo;
ll coin_one[19], coinTwo[19];
vector<ll> first;
map<ll, ll> second;

void fun(ll pos, ll sum, ll op)
{
    if (op == 1)
    {
        if (pos >= szOne)
        {
            first.push_back(sum);
            return;
        }
    }
    else
    {
        if (pos >= szTwo)
        {
            second[sum] = 1;
            return;
        }
    }

    ll val = 0;
    if (op == 1)
        val = coin_one[pos];
    else
        val = coinTwo[pos];

    fun(pos + 1, sum, op);
    fun(pos + 1, sum + val, op);
    fun(pos + 1, sum + 2 * val, op);
}

void solve()
{
    first.clear();
    second.clear();
    cin >> n >> k;
    if (n == 1)
    {
        ll a;
        cin >> a;
        if (a == k or 2 * a == k)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else
    {
        szOne = n / 2;
        szTwo = n - szOne;

        for (int i = 0; i < szOne; i++)
            cin >> coin_one[i];
        for (int i = 0; i < szTwo; i++)
            cin >> coinTwo[i];

        fun(0, 0, 1);
        fun(0, 0, 2);

        for (int i = 0; i < (int)first.size(); i++)
        {
            if (second.count(k - first[i]))
            {
                cout << "Yes\n";
                return;
            }
        }
        cout << "No\n";
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
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}