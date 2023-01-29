#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll ans = 1;
    vector<string> vst;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        vst.push_back(s);
    }

    for (int i = 0; i < m; i++)
    {
        set<char> st;
        for (int j = 0; j < n; j++)
            st.insert(vst[j][i]);

        ans = (ans * st.size()) % mod;
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