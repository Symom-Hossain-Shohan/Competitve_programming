#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<pair<ll, ll>> vp;
    for (int i = 0; i < m; i++)
    {
        ll l, r;
        cin >> l >> r;
        vp.push_back({l, r});
    }

    sort(vp.begin(), vp.end());

    vector<ll> ones(n + 1);
    for (int i = 0; i < n; i++)
        ones[i + 1] = ones[i] + (s[i] - '0');
    ll ans = 0;
    for (int i = 0; i < m - 1; i++)
    {
        if(vp[i].first==vp[i].second) 
        {
            // cout << i << 'k';
            continue;
        }
        if (vp[i].first == vp[i + 1].first)
        {
            // cout << "Yes\n"; 
            ll one = ones[vp[i + 1].second] - ones[vp[i].second];
            if ((one == 0 and ones[vp[i].second]-ones[vp[i].first-1]==0)or one == vp[i + 1].second - vp[i].second)
                continue;
            else
            {
                ans++;
                // cout << i << endl; 
            }
        }
        else
        {
            ll zeros = vp[i].second - vp[i].first + 1 - ones[vp[i].second] - ones[vp[i].first - 1];
            if (ones[vp[i].first + zeros - 1] - ones[vp[i].first - 1])
            {
                ans++;
                // cout << i << endl; 
            }
        }
    }
    ll i = m - 1;
    ll zeros = vp[i].second - vp[i].first + 1 - ones[vp[i].second] - ones[vp[i].first - 1];
    if (ones[vp[i].first + zeros - 1] - ones[vp[i].first - 1] and vp[i].first != vp[i].second)
    {
        ans++; 
        // cout << i << endl; 
    }

    

    cout << max(1ll, ans) << endl; 
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