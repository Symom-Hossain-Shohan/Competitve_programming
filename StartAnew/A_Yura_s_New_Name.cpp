#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s;
    cin >> s;
    if (s == "^")
    {
        cout << 1 << '\n';
        return; 
    }
    int ans = 0;
    if (s[0] == '_')
        ans++; 
    if (s.back() == '_')
        ans++; 
    for (int i = 0; i < (int)s.size() - 1; ++i)
    {
        if (s[i] == '_' && s[i + 1] == '_')
            ans++; 
    }
    cout << ans << '\n';
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