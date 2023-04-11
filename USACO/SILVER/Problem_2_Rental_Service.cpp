#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.second * b.first < b.first * a.second;
}

void solve()
{
    ll n, m, r;
    cin >> n >> m >> r;
    vector<ll> cow(n);
    for (auto &i : cow)
        cin >> i;
    sort(cow.begin(), cow.end());

    vector<pair<ll, ll>> milk(m);
    for (auto &i : milk)
        cin >> i.first >> i.second;
    vector<ll> rent(r);
    for (auto &i : rent)
        cin >> i;
    ;
    sort(rent.begin(), rent.end());
    sort(milk.begin(), milk.end(), cmp);

    ll ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ll mk = cow[i];
        ll t = 0;
        ll cnt = 0;
        for (int j = milk.size() - 1; j >= 0; j--)
        {
            if (mk <= milk[j].first)
            {
                t += (mk)*milk[j].second;
                cnt++;
                break;
            }
            else
            {
                t += milk[j].first * milk[j].second;
                cnt++;
                mk -= milk[j].first;
            }
        }
        if (t > rent.back())
        {
            ans += t;
            for (int j = milk.size() - 1; j >= 0; j--)
            {
                if (mk <= milk[j].first)
                {
                    milk[j].first -= mk; 
                    break;
                }
                else
                {
                    mk -= milk[j].first;
                    milk.pop_back();
                }
            }
        }
        else 
        {
            ans += rent.back();
            rent.pop_back();
        }
    }
    cout << ans << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}